// Scoring Class responsible for:
// Loss Point Function (lossPoint)   : When a Player comes collides with Debris score is negatively effected.
// Gain Point Function (getPoint)   :When a piece of Debris leaves game screen (on the left), score is positively effected.
class Scoring
{
private:
    int score; // score variable to store your score
    int point; // point variable to effect player's score 

public:
    Scoring() // Default Constructor
    {
        score = 100;    // game start with 100 points << default score
        point = 1;      // this is how much point your score will get effected
    }                   // Default Constructor
    Scoring(int _score) // Overloaded Constructor
    {
        score = _score;
    }
    void lossPoint()        // (Setter) set new player's score, when collision occures player's score get effected negatively
    {                       // by subtracting 1 from the player's score for each collision.
        int score = score - point; //score=score-x (100-1=99)
    }
    void gainPoint()        // (Setter) set new player's score, when collision occures player's score get effected negatively
    {                       // by subtracting 1 from the player's score for each collision.
        int score = score + point; //score=score+x (100-1=101)
    }
    int getScore() // getter to get your score
    {
        return score;
    }

        std::string PointtoString() // this will convert out int 'score' to a string and send it to Text class to print
    {
        std::string curentScore;
        std::ostringstream buffer;
        buffer << "Score: " << score;
        curentScore = buffer.str();
        return curentScore;
    }
    
};