#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"������¼"NOR, ({ "suanshu"}));
	set("long","����һ��"HIG"������¼"NOR"��ʹ������Ϊ250��360"ZJURL("cmds:kan bagua")+ZJSIZE(28)+"�о�"NOR"��\n");
	set("unit","��");
	set_weight(100);
	set("value",30000);
	set("yuanbao",50);	
    set("no_steal",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);           
	set("desc","������¼");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="bagua")
  	return notify_fail("��Ҫ��ʲô?\n");
      		
 if(me->query_skill("mathematics") < 249)
			return notify_fail("�����������֪̫���� ��\n");

 if(me->query_skill("mathematics") > 359)
			return notify_fail("������¼�Ѿ��ﲻ�� ��\n");

  me->set_skill("mathematics", me->query_skill("mathematics",1) + 1);

	write(HIY"���о�"HIG"������¼"HIY"ˢ�����Լ�����������֪!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }