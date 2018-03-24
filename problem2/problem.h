class products
{
    private:
        int product[256][8];
    public:
        products(){}

        void setstock(int prod_id, int col_id, int amount)
        {product[prod_id-1][col_id-1] = amount;}

        int getstock(int prod_id, int col_id)
        {return product[prod_id-1][col_id-1];}
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
        int prod_items(int prod_id, int col_id=0)
        {
            if (col_id == 8) return 0;
            else
            return product[prod_id-1][col_id]+prod_items(prod_id,col_id+1);
        }
        int prod_col(int prod_id, int col_id){return product[prod_id-1][col_id-1];}

        //~products(){delete(product);}
};