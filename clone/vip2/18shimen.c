
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIW"�Զ�ʦ�ŷ������ģ�"NOR, ({"quest sss"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "��");
		set("base_weight", 1);
		//set("base_value", 20000);
	   	set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("yuanbao",10);
		set("unit", "��");
		set("long","��˳���ƶ�����ǰʦ������npc��λ�ã�ʹ��˵����use quest sss;accept quest;���������\n");
		set("only_do_effect", 1);
	}
	setup();
}


int do_effect(object me)
{
	object ob;
	mapping q;
	string area;

	if (base_name(environment(me)) == "/d/city/wumiao")
			return notify_fail("�����������˽��ơ�\n");
	
	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");
	if(!mapp(q=me->query("quest")))
	{
      		return notify_fail("������û������ʹ���Զ�ʦ�Ÿ�ʲô?\n");  
	}
if (me->is_ghost()) 
		return notify_fail("���㻹������˵�ɡ�\n"); 
	
	 
	 
	if(q["type"]!="kill")
	{
      		return notify_fail("������û��ʦ����������ʹ�á�\n");  
	}
	if(ob=find_living(q["id"]))
	{
		sscanf(base_name(environment(ob)),"/d/%s/%*s",area);
               message_vision(HIC"��������������������������\n" , me);
		tell_object(me,HIR+q["name"]+NOR"��"+q["id"]+"��Ŀǰ����"HIW+MAP_D->query_map_short(area)+NOR"��"HIW+environment(ob)->query("short")+NOR"���\n");
me->move(environment(ob));
me->force_me("kill " + me->query("quest/id"));
	}
	else
		tell_object(me,"�޷��Զ���Ŀ�����������Ŀ�������ѱ�ɱ��������ʧ�ˡ�\n");
   if(random(2)==1)
   {
	add_amount(-1);
   }
	return 1;
}
