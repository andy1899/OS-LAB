class Threading1 extends Thread
{
	public void run()
	{
		for(int i=0;i<10;i++)
		{System.out.println("Child Thread");}
	}
}
class Test
{public static void main(String arg[])
	{Threading1 t=new Threading1();
	 t.start();
      	for(int i=0;i<10;i++)
		{System.out.println("Main Thread");}

	 }
}	 