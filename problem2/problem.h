/*
This file contains the source code of products checker it contains only one class that contains an 8 bit integer 2d array.
this array ccontains the stock of 256 products indexed from 0-255 with 8 different colors.
to access a specific color you have to use the color id from 1-8
*/
#include <stdint.h>
class products
{
    private:
        uint8_t product[256][8];
    public:
        //constructor
        products(){
            for(int i = 0; i < 256; i++)
            {
                for(int j = 0; j < 8; j++) product[i][j] = 0;
            }
        }

        //method that sets the stock of a specific product of specific color
        void setstock(int prod_id, int col_id, int amount)
        {product[prod_id-1][col_id-1] = amount;}

        //method that return the stock of a specific product of specific color
        uint8_t getstock(int prod_id, int col_id)
        {return product[prod_id-1][col_id-1];}

        //method that checks if a specific product is available with an option of checking wether a specific color of it available
        bool check_exist(int prod_id, int col_id=0)
        {
            if(col_id == 0)
            {
                for(int i = 0; i < 8; i++)
                {
                    if (product[prod_id][i] != 0) return 1;
                }
            }
            else{
                if(product[prod_id-1][col_id-1] != 0) return 1;
            }
            return 0;
        }
        //method that calculates the total amount of product items available
        //of all the different 8 colors
        int prod_items(int prod_id, int col_id=0)
        {
            if (col_id == 8) return 0;
            else
            return product[prod_id-1][col_id]+prod_items(prod_id,col_id+1);
        }
        //method that returns the number of items available for a specific product of specific color
        int prod_col(int prod_id, int col_id){return product[prod_id-1][col_id-1];}
        //method that return the total number of specifically colored product among all the different 256 products
        int allprod(int col_id, int prod_id = 0)
        {
            if (prod_id == 256) return 0;
            return product[prod_id][col_id-1]+allprod(col_id,prod_id+1);
        }
        //method that return the number of available products in the stock
        //without taking in consideration the colors
        int prod_types()
        {
            int total = 0;
            for (int i = 0; i < 256; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if (product[i][j] != 0)
                    {
                        total++;
                        break;
                    }
                }
            }
            return total;
        }

};