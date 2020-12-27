#include "minimax.h"
#include "helpers.h"
#include "move.h"

helpers helper;

int minimax::minimaxAlg(vector<string> &board, player &white, player &black, bool whitePlays, int depth){
    
    if(helper.evaluateBoard(board) != 0){
        return helper.evaluateBoard(board);
    }
    if(white.pawns.size()==0 && black.pawns.size()!=0) return INT_MIN;
    if(black.pawns.size() == 0 && white.pawns.size() != 0) return INT_MAX;
    int result = INT_MIN;
    bool noLegalMoves = true;
    if(whitePlays){
        for(int i = 0 ; i < white.pawns.size(); ++i){
            for(int j = 0 ; j < white.moves.size(); ++j){

                vector<string> currentBoard = board;
                player currentWhite = white, currentBlack = black;

                if(move(currentBoard,currentWhite,currentBlack,currentWhite.pawns[i],currentWhite.moves[j])){
                    noLegalMoves = false;
                    int res = minimaxAlg(currentBoard,currentWhite,currentBlack,!whitePlays,depth+1);
                    if (res > result){
                        result = res;
                    }
                }
            }
        }
        
        
        if(noLegalMoves){
            
            if(whitePlays) return INT_MIN;
            else return INT_MAX;
            
            
        }
    }

    else{  
        for(int i = 0 ; i < black.pawns.size(); ++i){
            for(int j = 0 ; j < black.moves.size(); ++j){

                vector<string> currentBoard = board;
                player currentWhite = white, currentBlack = black;

                if(move(currentBoard,currentBlack,currentWhite,currentBlack.pawns[i],currentBlack.moves[j])){
                    noLegalMoves = false;
                    int res = minimaxAlg(currentBoard,currentWhite,currentBlack,!whitePlays,depth+1);
                    if (res < result){
                        result = res;
                    }
                }
            }
        }
     
        if(noLegalMoves){
            
            if(whitePlays) return INT_MIN;
            else return INT_MAX;
        }

    }

    return result;
}