#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"Ǳ�ܿ�"NOR, ({"potcard"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long" ,HIY "����һ��Ǳ�ܿ����������ѣ��������"ZJURL("cmds:cun potential")+ZJSIZE(20)+"��Ǳ��"NOR"����"ZJURL("cmds:qu potential")+ZJSIZE(20)+"ȡǱ��"NOR"����"ZJURL("cmds:checkqn")+ZJSIZE(20)+"��Ǳ��"NOR""HIY"��"HIR"\n"HIY"��ħף��ʹ����죡mua~"NOR"\n");
                set("no_get", 1);
                set("no_drop", 1);
				set("no_put",1);
                set("no_give", 1);
				set("yuanbao", 500);
                set("no_sell", 1);
                set("no_steal", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
	add_action("do_cun","cun");
	add_action("do_checkqn","checkqn");
	add_action("do_ququ","qu");
}

int do_cun(string arg)
{
	int qiann = (int)this_player()->query("qiann");
	int cost,qn;
	object me = this_player();
	
	qn = me->query("potential")-me->query("learned_points");
	if(qn<=0)
		return notify_fail(HIR"��û��Ǳ�ܿ��Դ棡\n"NOR);

	if( !arg || (!sscanf(arg, "%d", cost)) ) 
		return notify_fail(INPUTTXT("��������Ǳ�ܣ�����Դ�"HIY+qn+NOR"��Ǳ��","cun $txt#")+"\n");

	if(cost==1)
		return notify_fail("�������Ѷ�����!\n");

	if(cost<=0)
		return notify_fail(HIR"����ƾ�����죿\n"NOR);

	if( cost > me->query("potential")-me->query("learned_points") )
		return notify_fail("���Ǳ�ܲ��㣬�޷���"HIW"Ǳ�ܿ�"NOR"�д����㹻��Ǳ�ܣ�\n");

	me->add("qiann",cost);
	me->add("learned_points", cost);
	tell_object(me,HIC"����"HIW"Ǳ�ܿ�"HIC"�ڴ�����"+cost+"Ǳ�ܡ�"NOR"\n");	

	return 1;
}

int do_ququ(string arg)
{
	int cost;
	int qn;
	object me = this_player();
	qn = me->query("qiann");
	
	if( me->query("qiann") <= 0 )
		return notify_fail(HIW"Ǳ�ܿ�"NOR"�д����Ǳ���Ѿ�û���ˣ�\n");

    if( !arg || (!sscanf(arg, "%d", cost)) ) 
		return notify_fail(INPUTTXT("����ȡ����Ǳ�ܣ������ȡ"HIY+qn+NOR"��Ǳ��","qu $txt#")+"\n");

	if(cost<=0)
		return notify_fail(HIR"����Ц���㣿\n"NOR);
	
	if( cost > me->query("qiann"))
		return notify_fail(HIR"��������ô��Ǳ�ܣ���������\n"NOR);
	
	me->add("qiann",-cost);
	me->add("learned_points", -cost);
	tell_object(me,HIC"���"HIW"Ǳ�ܿ�"HIC"��ȡ����"+cost+"Ǳ�� ��"NOR"\n");
		
	return 1;
}

int do_checkqn(string arg)
{
	int qn;
	object me = this_player();
	qn = me->query("qiann");

	if(qn==0)
	{
	write(ZJOBLONG+HIY"��ħ��ܰ������:��û��Ǳ�ܴ��\n"NOR);
	return 1;
	}

	write(ZJOBLONG+HIW"��ħ������:�����"HIY+qn+HIW"Ǳ�ܡ�\n"NOR);
	return 1;
}

int query_autoload() { return 1; }