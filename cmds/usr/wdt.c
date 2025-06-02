//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object slnpc,slroom,*slrooms;
	mixed last,now;
	mapping fam;
	int lvl,i;
	string *slnpcs;
	now = localtime(time());
	me = this_player();
	
		if(me->query("combat_exp")<100000)
		{
		tell_object(me,"���ʵս��Ϊ̫�ͣ�����������������\n");
		return 1;
	}
		if(me->query("wdtcs")<1)
		{
		tell_object(me,"����մ����Ѿ����꣡\n");
		return 1;
	}
	if(me->query_condition("killer")){
		tell_object(me,"�����ڱ�ͨ��������������������\n");
		return 1;
	}
	if (me->over_encumbranced()) 
		return notify_fail("��ĸ��ɹ��أ��������á�\n"); 
	
	if (me->query_encumbrance() < 0) 
		return notify_fail("��ĸ��ɳ��ֹ��ϣ��������á�\n"); 

	if (me->query_temp("sleeped")) 
		return notify_fail("�������������ء�\n");
    if (me->query("wudaota")>70) 
		return notify_fail("�����Ŀǰ�����ʮ�㡣\n");
	if (me->is_in_prison())   
		return notify_fail("�����������أ������ʲô����\n");
				
	if (me->is_fighting()) 
		return notify_fail("����������ս����\n");

	if (me->is_busy() || me->query("doing")) 
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

	if (me->query_temp("is_flying")) 
		return notify_fail("���������ڷ����У�\n");
		
			if (me->is_ghost()) 
		return notify_fail("���㻹������˵�ɡ�\n"); 
		
	if (environment(me)->query("no_magic") || environment(me)->query("no_fly"))
		return notify_fail("�㷢�������е�Ź֣���������������ָ�ӣ�\n");	
	slrooms = children("/d/fuben/wudaotai/wudaotai");
	for (i = 0; i < sizeof(slrooms); i++) {
		if(slrooms[i]->query("owner")==me->query("id"))
			slroom = slrooms[i];
	}
	if(!slroom)
	{
		slroom = new("/d/fuben/wudaotai/wudaotai");
		slroom->set("owner",me->query("id"));
		if(!me->query("wudaota")){
			lvl =me->query("wudaota");
			if(lvl<1) lvl = 1;
			me->set("wudaota",1);
			me->set("last_wudaota",time());
		}
		slroom->set("sllv",me->query("wudaota"));
		slnpcs = ({
			"d/fuben/wudaotai/npc/sldz",
		});
		slnpc = new(slnpcs[random(sizeof(slnpcs))]);
		if(me->query("wudaota")<10)
		slnpc->set("name","��"+chinese_number(me->query("wudaota"))+"�ػ���");
	    else if(me->query("wudaota")==10)
		slnpc->set("name",HIG"���ָ���"NOR"");
	    else if(me->query("wudaota")<30)
		slnpc->set("name",HIC"��ʿ"+chinese_number(me->query("wudaota"))+""NOR"");
	    else if(me->query("wudaota")==30)
		slnpc->set("name",HIY"��������"NOR);
	    else if(me->query("wudaota")<70)
		slnpc->set("name",HIY"������"+chinese_number(me->query("wudaota"))+""NOR"");
	    else if(me->query("wudaota")==70)
		slnpc->set("name",HIC"��"HIG"��"""NOR"");
	}
	this_player()->move(slroom);
	if(objectp(slnpc))
		slnpc->move(slroom);
	return 1;
}

int help (object me)
{

	return 1;
}