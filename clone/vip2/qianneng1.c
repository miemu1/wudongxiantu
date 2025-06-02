#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"��Ϊ��"NOR, ({"potcard1"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long" ,HIY "����һ����Ϊ�����������ѣ��������"ZJURL("cmds:cunn combat_exp")+ZJSIZE(20)+"����Ϊ"NOR"����"ZJURL("cmds:ququ combat_exp")+ZJSIZE(20)+"ȡ��Ϊ"NOR"����"ZJURL("cmds:checkqn")+ZJSIZE(20)+"����Ϊ"NOR""HIY"��"HIR"\n"HIY"Ц��ף��ʹ����죡mua~"NOR"\n");
                set("no_get", 1);
                set("no_drop", 1);
				set("no_put",1);
                set("no_give", 1);
				set("yuanbao", 2500);
                set("no_sell", 1);
                set("no_steal", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
	add_action("do_cun","cunn");
	add_action("do_checkqn","checkqn");
	add_action("do_ququ","ququ");
}

int do_cun(string arg)
{
	int qiann = (int)this_player()->query("qiann");
	int cost,qn;
	object me = this_player();
	
	qn = me->query("combat_exp")-me->query("learned_points");
	if(qn<=0)
		return notify_fail(HIR"��û����Ϊ���Դ棡\n"NOR);

	if( !arg || (!sscanf(arg, "%d", cost)) ) 
		return notify_fail(INPUTTXT("����������Ϊ������Դ�"HIY+qn+NOR"����Ϊ","cunn $txt#")+"\n");

	if(cost==1)
		return notify_fail("�������Ѷ�����!\n");

	if(cost<=0)
		return notify_fail(HIR"����ƾ�����죿\n"NOR);

	if( cost > me->query("combat_exp")-me->query("learned_points") )
		return notify_fail("�����Ϊ���㣬�޷���"HIW"��Ϊ��"NOR"�д����㹻����Ϊ��\n");

	me->add("qiann",cost);
	me->add("learned_points", cost);
	tell_object(me,HIC"����"HIW"��Ϊ��"HIC"�ڴ�����"+cost+"��Ϊ��"NOR"\n");	

	return 1;
}

int do_ququ(string arg)
{
	int cost;
	int qn;
	object me = this_player();
	qn = me->query("qiann");
	
	if( me->query("qiann") <= 0 )
		return notify_fail(HIW"��Ϊ��"NOR"�д������Ϊ�Ѿ�û���ˣ�\n");

    if( !arg || (!sscanf(arg, "%d", cost)) ) 
		return notify_fail(INPUTTXT("����ȡ������Ϊ�������ȡ"HIY+qn+NOR"����Ϊ","ququ $txt#")+"\n");

	if(cost<=0)
		return notify_fail(HIR"����Ц���㣿\n"NOR);
	
	if( cost > me->query("qiann"))
		return notify_fail(HIR"��������ô����Ϊ����������\n"NOR);
	
	me->add("qiann",-cost);
	me->add("learned_points", -cost);
	tell_object(me,HIC"���"HIW"��Ϊ��"HIC"��ȡ����"+cost+"��Ϊ ��"NOR"\n");
		
	return 1;
}

int do_checkqn(string arg)
{
	int qn;
	object me = this_player();
	qn = me->query("qiann");

	if(qn==0)
	{
	write(ZJOBLONG+HIY"��ܰ������:��û����Ϊ���(��������)\n"NOR);
	return 1;
	}

	write(ZJOBLONG+HIW"������:�����"HIY+qn+HIW"��Ϊ��\n"NOR);
	return 1;
}

int query_autoload() { return 1; }