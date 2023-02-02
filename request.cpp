#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

class RequestArgs{
    public:
        static constexpr const char* REQUEST_TYPE = "RequestType";
        static constexpr const char* ORDER_ID = "OrderID";
        static constexpr const char* TOKEN = "Token";
        static constexpr const char* SYMBOL = "Symbol";
        static constexpr const char* SIDE = "Side";
        static constexpr const char* PRICE = "Price";
        static constexpr const char* QUANTITY = "Quantity";
        static constexpr const char* QUNATITY_FILLED = "QuantityFilled";
        static constexpr const char* DISCLOSED_QNTY = "DisclosedQnty";
        static constexpr const char* TIME_STAMP = "TimeStamp";
        static constexpr const char* DURATION = "Duration";
        static constexpr const char* ORDER_TYPE = "OrderType";
        static constexpr const char* ACCOUNT = "Account";
        static constexpr const char* EXCHANGE = "Exchange";
        static constexpr const char* NUM_COPIES = "NumCopies";
};

class Request{
    private:
        string request_type;
        int order_id;
        int token;
        string symbol;
        string side;
        long double price;
        int quantity;
        int quantity_filled;
        int disclosed_qnty;
        long long time_stamp;
        string duration;
        string order_type;
        string account;
        int exchange;
        int num_copies;
    public:
        Request (string request_type,
                 int order_id,
                 int token,
                 string symbol,
                 string side,
                 long double price,
                 int quantity,
                 int quantity_filled,
                 int disclosed_qnty,
                 long long time_stamp,
                 string duration,
                 string order_type,
                 string account,
                 int exchange,
                 int num_copies
                 ){
            this->request_type = request_type;
            this->order_id = order_id;
            this->token = token;
            this->symbol = symbol;
            this->side = side;
            this->price = price;
            this->quantity = quantity;
            this->quantity_filled = quantity_filled;
            this->disclosed_qnty = disclosed_qnty;
            this->time_stamp = time_stamp;
            this->duration = duration;
            this->order_type = order_type;
            this->account = account;
            this->exchange = exchange;
            this->num_copies = num_copies;
        }
        static Request parse(string &str, int N){
            string entry="";
            string key, value;
            
            string request_type;
            int order_id;
            int token;
            string symbol;
            string side;
            long double price;
            int quantity;
            int quantity_filled;
            int disclosed_qnty;
            long long time_stamp;
            string duration;
            string order_type;
            string account;
            int exchange;
            int num_copies;
            
            for (int i=0; i<=N; i++){
                if (i==N || str[i]=='|' || str[i]==':'){
                    if (str[i]==':'){
                        key = entry;
                    } else {
                        value = entry;

                        if (key == RequestArgs::REQUEST_TYPE)
                        request_type = value;
                        else if (key == RequestArgs::ORDER_ID)
                            order_id = stoi(value);
                        else if (key == RequestArgs::TOKEN)
                            token = stoi(value);
                        else if (key == RequestArgs::SYMBOL)
                            symbol = value;
                        else if (key == RequestArgs::SIDE)
                            side = value;
                        else if (key == RequestArgs::PRICE)
                            price = stold(value);
                        else if (key == RequestArgs::QUANTITY)
                            quantity = stoi(value);
                        else if (key == RequestArgs::QUNATITY_FILLED)
                            quantity_filled = stoi(value);
                        else if (key == RequestArgs::DISCLOSED_QNTY)
                            disclosed_qnty = stoi(value);
                        else if (key == RequestArgs::TIME_STAMP)
                            time_stamp = stoll(value);
                        else if (key == RequestArgs::DURATION)
                            duration = value;
                        else if (key == RequestArgs::ORDER_TYPE)
                            order_type = value;
                        else if (key == RequestArgs::ACCOUNT)
                            account = value;
                        else if (key == RequestArgs::EXCHANGE)
                            exchange = stoi(value);
                        else if (key == RequestArgs::NUM_COPIES)
                            num_copies = stoi(value);
                        
                    }

                    entry = "";
                    continue;
                }
                else
                    entry += str[i];
                
            }
            return Request(request_type, order_id, token, symbol, side, price, quantity,
                           quantity_filled, disclosed_qnty, time_stamp, duration, order_type,
                           account, exchange, num_copies);
        }
        void print_time_stamp(){
            cout<<this->time_stamp<<endl;
        }
        void print_price(){
            cout<<setprecision(20)<<this->price<<endl;
        }
};

map<string, string> parse_request(string &str, int N){
    string entry="";
    string key, value;
    map <string, string> request_map;
    
    for (int i=0; i<=N; i++){
        if (i==N || str[i]=='|' || str[i]==':'){
            if (str[i]==':'){
                key = entry;
            } else {
                value = entry;
                request_map.insert({key, value});
            }
            entry = "";
            continue;
        }
        else
            entry += str[i];
        
    }
    return request_map;
}

int main(){
    ifstream myfile ("request_480069891");
    string mystring;
    double h=4.0;

    if (myfile.is_open()){
        myfile >> mystring;
        int N = mystring.length();
        // map<string, string> request_map = parse_request(mystring, N);
        // map<string, string>::iterator it = request_map.begin();

        Request request = Request::parse(mystring, N);

        // while (it != request_map.end()){
        //     cout<<it->first<<":\t"<<it->second<<endl;
        //     it++;
        request.print_time_stamp();
        request.print_price();
        cout<<h;
        }
}
