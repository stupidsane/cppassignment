//assignment   question number 5.....
// add two times provided in hour and minute format.... using class
  #include<iostream>
  #include<conio.h>
   using namespace std;
     class time
     {
     	  int hours;
     	  int minutes;
     	    public:
     	    	 void get()
     	    	 { int i=0;
                     do{
                        
     	    	 	cout<<"\n\nEnter time  in HH:MM  format :";
     	    	 	scanf("%d:%d", &hours,&minutes);
                    if(hours<0||hours>24||minutes<0||minutes>60)
                        cout<<"wrong entry";
                    else
                        i=1;
                     }while(i==0);
				  }
				  void sumtime(time , time );
				  void display()
				  {
				    cout<<"\nTime after addition  ...\n";	
				    cout<<hours<<" hours and "<<minutes<<" minutes ";
				  }
	 };
	     void time::sumtime(time t1, time t2)
	     {
	     	 minutes = t1.minutes + t2.minutes;
	     	 hours = minutes/60;
	     	 minutes = minutes%60;
	     	 hours = hours + t1.hours + t2.hours;
		 }
		   int main()
		   {
		   	  time a,b,c;
		   	  cout<<"\nTITLE : add two times provided in hour and minute format.... using class";
		   	  a.get();
			  b.get();
			  c.sumtime(a,b);
			  c.display();
			  return 0;
			  		   }
