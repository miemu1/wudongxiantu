// sl_cloth.c

#include <ansi.h>

inherit ITEM;


void create()
{
        set_name(HIW"����"NOR, ({"potcard"}));
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("text" , "��"ZJURL("http://m.hao123.comp")+ZJSIZE(20)+"ע��"NOR"(zhuru potential)��"ZJURL("cmds:xi potential")+ZJSIZE(20)+"��ȡ"NOR"(xi potential)�Ĺ�Ч��"NOR"\n");
		set("long",HIW+query("text") );
                set("value", 8000);
            set("yuanbao", 24);
			  set("no_give",1);
    set("no_sell",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_sell", 1);
                set("material", "stone");
        }
        setup();
}

void init()
{
	add_action("do_zhuru","zhuru");
	add_action("do_xiqu","xi");
}

int do_zhuru(string arg)
{
	int cost,max_potential;
	object me = this_player();


	if  
		(arg!="potential")
		 {
		return notify_fail("��Ҫ����ʲô?\n");
       }
 
    else if((me->query("potential")) <= 52500 )
			   {
		return notify_fail("���Ǳ�ܲ��㣨1%�������ѣ���\n");
	 }
	 
	else if((me->query("potential1"))>= 20000000 )
			 {
		return notify_fail("�Ѿ���ӯ�����޷��������Ǳ�ܣ�\n");
	 }
  


	
	me->add("potential" , -52500);//�ٷ�֮4������
        me->add("potential1" , 50000);
	//message_vision(HIC"$N"HIC"�㣬��Ǳ���������С�"NOR"\n",me);
      tell_object(me,HIC"�㣬��Ǳ���������С�"NOR"\n");
tell_object(me,HIR"Ŀǰ��ħʯ�д���"+me-> query("potential1")+"��Ǳ�ܡ�"NOR"\n");
  	
me->save();	

	return 1;
}

int do_xiqu(string arg)
{

	object me = this_player();

	if (arg!="potential")
		return notify_fail("��Ҫ��ȡʲô?\n");

   else   
	if( (me->query("potential1"))<50000 )
		return notify_fail("�����Ǳ���Ѿ����Ĺ��ˣ�\n");

	

	
	me->add("potential1" , -50000);
	me->add("potential" , 50000);//�ٷ�֮4������


     

        tell_object(me,HIC"��˫���鰴Ǳ�ܿ���������ȡǱ�ܡ�"NOR"\n");	

      
tell_object(me,HIR"Ŀǰ��ħʯ�д���"+me-> query("potential1")+"��Ǳ�ܡ�"NOR"\n");
me->save();
	return 1;
}


int query_autoload() { return 1; }