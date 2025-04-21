//Math Quiz Project 
//Author Jawad Alotaibi
#include <iostream> 
#include <cstdlib>

using namespace std;

enum enQuestionLevel {Easy = 1, Mid = 2 , Hard = 3 , Random = 4};
enum enOperationType {Add = 1, Sub = 2 , Mul = 3, Div = 4 , Mix = 5};

struct stQuiz {

    int NumberOfQuestions;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    int NumberOfRightAnswer;
    int NumberOfWrongAnswer;
};

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

int ReadNumber(string message)
{
    int Number = 0;

    do
    {
        cout << message;
        cin >> Number;
    } while (Number < 0);


    return Number;
}

int RandomNumber(int from, int to)
{
    int randomNumber = 0;

    randomNumber = rand() % (to - from + 1) + from;
    return randomNumber;
}

void GetEasyQuestion(int &num1 , int &num2)
{
    num1 = RandomNumber(1, 9);
    num2 = RandomNumber(1, 9);
}


void GetMidQuestion(int &num1 , int &num2)
{
    num1 = RandomNumber(15, 30);
    num2 = RandomNumber(1, 15);
}


void GetHardQuestion(int &num1 , int &num2)
{
    num1 = RandomNumber(25, 50);
    num2 = RandomNumber(1, 25);
}

int Addition(int num1, int num2)
{
    cout << num1 << "\n" << num2 << "+\n" << "---------------------------------------";
    return (num1 + num2);
}

int Subtraction(int num1, int num2)
{
    cout << num1 << "\n" << num2 << "-\n" << "---------------------------------------";
    return (num1 - num2);
}

int Multiplication(int num1 , int num2)
{
    cout << num1 << "\n" << num2 << "X\n" << "---------------------------------------";
    return (num1 * num2);
}

int Division(int num1, int num2)
{
    cout << num1 << "\n" << num2 << "/\n" << "---------------------------------------";
    return (num1, num2);
}


enQuestionLevel GetQuestionLevel()
{
    int NumOfQuestionLevel = 0;

    cout << "Enter Question Level [1] Easy, [2] Mid, [3] Hard, [4] Mix ? ";
    cin >> NumOfQuestionLevel;

    return (enQuestionLevel) NumOfQuestionLevel;
}

enOperationType GetOperatioNType()
{
    int operationType = 0;

    cout << "Enter Operation Type [1] Addition, [2] Subtraction, [3] Multiplication, [4] Div ? ";
    cin >> operationType;

    return (enOperationType) operationType;
}

int GetQuesion(enOperationType OperationType , enQuestionLevel QuestionLevel)
{
    int num1 = 0 , num2 = 0;

    if(QuestionLevel == enQuestionLevel::Random)
    {
        QuestionLevel = enQuestionLevel(RandomNumber(1,3));
    }

    switch(QuestionLevel)
    {
      case enQuestionLevel::Easy:
            GetEasyQuestion(num1 , num2);
            break;

        case enQuestionLevel::Mid:
            GetMidQuestion(num1, num2);
            break;

        case enQuestionLevel::Hard:
            GetHardQuestion(num1, num2);
            break;
    }

        if(OperationType == enOperationType::Mix)
        {
            OperationType = enOperationType(RandomNumber(1,4));
        }
    switch(OperationType)
    {
        case enOperationType::Add:
          return  Addition(num1, num2);
            break;
        
        case enOperationType::Sub:
           return Subtraction(num1, num2);
            break;
        
            case enOperationType::Mul:
               return Multiplication(num1, num2);
                break;
            
        case enOperationType::Div:
            return Division(num1, num2);
            break;
    }

}

stQuiz FillFinalResult(int numberOfQuestions, enQuestionLevel QuestionLevel , enOperationType OperationType, int RightAnswer, int WrongAnswer)
{
    stQuiz Quiz;
    Quiz.NumberOfQuestions = numberOfQuestions;
    Quiz.NumberOfRightAnswer = RightAnswer;
    Quiz.NumberOfWrongAnswer = WrongAnswer;
    Quiz.OperationType = OperationType;
    Quiz.QuestionLevel = QuestionLevel;

    return Quiz;
}


string GetLevelName(enQuestionLevel QuestionLevel)
{
    string Levels[] = {"Easy", "Mid", "Hard","Mix"};

    return Levels[QuestionLevel -1];
}

string GetOperatioNName(enOperationType OpType)
{
    string OperationsType[] = {"Addition", "Subtraction", "Multiplication", "Div", "Mix"};

    return OperationsType[OpType - 1];
}


stQuiz MathQuiz(int numberOfQuestions)
{
    stQuiz Quiz;
    int numOfRightAnswer = 0 , numOfWrongAnswer = 0, answer = 0 , userAnswer = 0;

   enQuestionLevel QuestionLevel = GetQuestionLevel();
   enOperationType OperationType = GetOperatioNType();

    for(int currentQuestion = 1; currentQuestion <= numberOfQuestions; currentQuestion++)
    {
        cout << "Question " << "[" << currentQuestion << "/" << numberOfQuestions << "]\n\n";
        answer = GetQuesion(OperationType, QuestionLevel);
        cout << endl;
        cin >> userAnswer;

        if(userAnswer == answer)
        {
            system("color 2F"); // Turn screen to green
            cout << "Right answer (:\n";
            numOfRightAnswer++;
        }
        else
        {
            system("color 4F"); // Turn screen to red
            cout << "Wrong answer The Rigth answer is: " << answer << "\n";
            numOfWrongAnswer++;

        }
    }

   return FillFinalResult(numberOfQuestions, QuestionLevel , OperationType, numOfRightAnswer, numOfWrongAnswer);

}
//stopped here i need to build final result dashboard
void ShowFinalResult(stQuiz QuizResult)
{
    cout << "----------------------------------------------------\n";
        if(QuizResult.NumberOfRightAnswer > QuizResult.NumberOfWrongAnswer)
        {
            cout << "\tFinal Result is Pass\n";
        }
        else
        {
            cout << "\tFinal Result is Fail\n";
        }

        cout << "----------------------------------------------------\n\n";


        cout << "Number Of Questions    : " << QuizResult.NumberOfQuestions << endl;
        cout << "Question Level         : " << GetLevelName(QuizResult.QuestionLevel) << endl; 
        cout << "Operation Type         : " << GetOperatioNName(QuizResult.OperationType) << endl;
        cout << "Number Of Right answer : " << QuizResult.NumberOfRightAnswer << endl;
        cout << "Number Of Wrong answer : " << QuizResult.NumberOfWrongAnswer << endl;

        cout << "----------------------------------------------------\n\n";


}


void StartQuiz()
{
    char PlayAgain = 'y';
    do
    {
        ResetScreen();
        stQuiz QuizResult = MathQuiz(ReadNumber("How Many Questions do you want to answer? "));
        ShowFinalResult(QuizResult);

        cout << "\nDo you want to play again ? ";
        cin >> PlayAgain;

        
    } while (tolower(PlayAgain) == 'y');
    
    
}
int main()
{
    StartQuiz();
    ResetScreen();
    return 0;
}