#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENCE("GPL");

__init int ex04_simple_module_function1(void)
{	
	printk(KERN_ALERT "Inside the Function1\n" __FUNCTION__);
	return 0;
}

int ex04_simple_module_function2(void)
{
	printk(KERN_ALERT "inside function 2\n",__FUNCTION__)
	return 0;
}

__init int count=5;

__init int ex01_simple_module_init(void)
{	
	int index =0;
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	for(index=0;index<count;index++)
	{
		printk(KERN_ALERT "INDEX= %d\n",__FUNCTION__);
	}
	
	ex04_simple_module_function1();
	ex04_simple_module_function2();

	return 0;
}

void ex01_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	ex04_simple_module_function2();
}

module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);
