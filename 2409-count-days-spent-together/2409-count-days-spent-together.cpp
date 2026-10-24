class Solution {
public:
    int convertmonthtodate(int month,int date){
        int overall_date=0;
        if(month==01){
            overall_date=date;
        }
        if(month==02){
            overall_date=31+date;
        }
        if(month==03){
            overall_date=31+28+date;
        }
        if(month==04){
            overall_date=31+28+31+date;
        }
        if(month==05){
            overall_date=31+28+31+30+date;
        }
        if(month==06){
            overall_date=31+28+31+30+31+date;
        }
        if(month==07){
            overall_date=31+28+31+30+31+30+date;
        }
        if(month==8){
            overall_date=31+28+31+30+31+30+31+date;
        }
        if(month==9){
            overall_date=31+28+31+30+31+30+31+31+date;
        }
        if(month==10){
            overall_date=31+28+31+30+31+30+31+31+30+date;
        }
        if(month==11){
            overall_date=31+28+31+30+31+30+31+31+30+31+date;
        }
        if(month==12){
            overall_date=31+28+31+30+31+30+31+31+30+31+30+date;
        }
        return overall_date;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int arrivealice=convertmonthtodate(
            (arriveAlice[0]-'0')*10+(arriveAlice[1]-'0'),
            (arriveAlice[3]-'0')*10+(arriveAlice[4]-'0')
        );

        int leavealice=convertmonthtodate(
           (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0'),
            (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0')
        );
        int arrivebob=convertmonthtodate(
            (arriveBob[0]-'0')*10 + (arriveBob[1]-'0'),
            (arriveBob[3]-'0')*10 + (arriveBob[4]-'0')
        );
        
        int leavebob=convertmonthtodate(
            (leaveBob[0]-'0')*10+(leaveBob[1]-'0'),
            (leaveBob[3]-'0')*10+(leaveBob[4]-'0')
        );

        int start=max(arrivealice,arrivebob);
        int end=min(leavealice,leavebob);

        if(start>end){
            return 0;
        }
        else{
            return end-start+1;
        }
    }
};