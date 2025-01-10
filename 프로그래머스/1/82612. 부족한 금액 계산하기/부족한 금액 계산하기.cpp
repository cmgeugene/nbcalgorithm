using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long pricesum = 0;
    for(int i = 0; i <= count; i++){
        pricesum += price*i; 
    }
    if(pricesum > money)
        answer = pricesum - money;
    else return 0;

    return answer;
}