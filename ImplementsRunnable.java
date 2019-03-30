class Threading2 implements Runnable
{ public void run()
	{for(int i=0;i<10;i++)
		{System.out.println("Child Thread");}
	}
}
class ThreadDemo
{
	public static void main(String arg[])
	{
		Threading2 t=new Threading2();
		Thread t1=new Thread(t);
		t1.start();
		for(int i=0;i<10;i++)
		{System.out.println("Main Thread");}
	}
}