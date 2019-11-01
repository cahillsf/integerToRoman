#include <string>

class Solution {
public:
    string intToRoman(int num) {
        std::string res = "";
        int funcNum = num;
        int multiplier = 1;
        std::string ones = "", tens = "", hundreds = "", thousands = "";
        while (funcNum > 0){
            int currNum = funcNum % 10;
            currNum *= multiplier;
            std::cout<<"curr num is "<<currNum<<endl;
            if(currNum < 10){
                if (currNum == 9){
                    ones = "IX";
                    currNum -= 9;
                }
                if(currNum >= 5){
                    ones = "V";
                    currNum -= 5;
                }
                if(currNum == 4){
                    ones.append("IV");
                    currNum -= 4;
                }
                for(int i = 0; i < currNum; i++){
                    ones.push_back('I');
                    
                }
            }
            else if(currNum < 100){
                if(currNum == 90){
                    tens = "XC";
                    currNum -= 90;
                }
                if(currNum >= 50){
                    tens = "L";
                    currNum -= 50;
                }
                if(currNum == 40){
                    tens = "XL";
                    currNum -= 40;
                }
                for(int i = 0; i < (currNum/10); i++){
                    tens.push_back('X');
                }
                
            }
            else if (currNum < 1000){
                if(currNum == 900){
                    hundreds = "CM";
                    currNum -= 900;
                }
                if(currNum >= 500){
                    hundreds = "D";
                    currNum -= 500;
                }
                if(currNum == 400){
                    hundreds = "CD";
                    currNum -= 400;
                }
                for(int i = 0; i < (currNum/100); i++){
                    hundreds.push_back('C');
                }
                
            }
            else{
                for(int i = 0; i < (currNum/1000); i++){
                    thousands.push_back('M');
                }
                
            }
            funcNum /= 10;
            multiplier *= 10;
            
        }
        res = thousands + hundreds + tens + ones;
        return res; 
    }       
};