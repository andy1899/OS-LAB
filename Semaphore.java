

import java.util.Scanner;

public class Semaphore {
    int choice,E=5,F=0,S=1;
    void start()
    { System.out.println("Press 1.for producer. Press 2.for consumer. Press 3 for exit");
       
         Scanner sc=new Scanner(System.in);
         choice=sc.nextInt();
         switch(choice)
          {
             case 1:
             { if((S==1)&&(E!=0))
                producer();
               else
                     System.out.println("Buffer is Full");
                 break;
             }
             case 2:
             {if((S==1)&&(F!=0))
                consumer();
               else
                     System.out.println("Buffer is Empty");
               
                 break;
             }
             case 3:
             { System.out.println("Your choice is to exit");
                 break;
             }
             default:
             {
                 System.out.println("Wrong choice entered");
                 break;
             }
           }
         System.out.println("Press 1 to continue");
         int c=sc.nextInt();
         if(c==1)
             start();
    }
    void producer()
    { System.out.println("Buffer Empty space before utilisation="+E);
        System.out.println("Buffer Full space before utlisation="+F);
     wait(E);
     wait(S);
        E--;
     F++;
        System.out.println("Buffer Empty space after producer utilisation="+E);
        System.out.println("Buffer Full space after producer utlisation="+F);
     signal(S);
     signal(F);
    }
    void consumer()
    { wait(F);
      wait(S);
       System.out.println("Buffer Empty space before consumer utilisation="+E);
        System.out.println("Buffer Full space before consumer utlisation="+F);
       
      E++;
        F--;
         System.out.println("Buffer Empty space after consumer utilisation="+E);
        System.out.println("Buffer Full space after consumer utlisation="+F);
       
        signal(S);
        signal(E);
    }
    int wait(int S)
    {
        while(S<=0);
        return --S;
    }
    int signal(int S)
    {
        return ++S;
    }
    
    public static void main(String[] args) {
     
     Semaphore ob=new Semaphore();
     ob.start();
    }
    
}