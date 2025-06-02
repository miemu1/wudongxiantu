inherit ROOM;

#include <localtime.h>

int start_moku_fuben(object who);
void end_fuben_moku(object me, object moku);
private void init_player(object me);
int check_out(object me);
private void restore_status(object me);

void create()
{
	set("short", "ħ��һ��");
	set("long", @LONG
���ﳣ�걻а����Ⱦ��Ѫħ���Ĵ����ߡ�
LONG);
	
	set("action_list", ([
		"�뿪����" : "likai",
		]));
	
	set("no_magic", 1);
	set("no_clean_up_fb", 1);
	
	setup();
}

void init()
{
	add_action("do_likai", "likai");
}

int do_likai(string arg)
{
	if(!arg)
		return notify_fail(ZJOBLONG + "��ȷ��Ҫ�뿪������\n" ZJOBACTS2 + "ȷ��:likai y\n");
	
	if(arg == "y")
	{
		remove_call_out("end_fuben_moku");
		restore_status(this_player());
		this_player()->move("d/city/kedian");
	}
	destruct(this_object());
	return 1;
}

int start_fuben_moku(object who)
{
	int last_time;
	object room, xuemo;
	
	last_time = who->query("fuben_moku/last_time");
	if ((localtime(last_time)[LT_MON] == localtime(time())[LT_MON]) && (localtime(last_time)[LT_MDAY] == localtime(time())[LT_MDAY]))
	{
		tell_object(who, "ħ��а�����أ�һ���޷��������Ρ�\n");
		return 0;
	}

	xuemo = new(__DIR__"xuemo");
	xuemo->init_npc(who, xuemo);
	xuemo->move(this_object());
	who->set("fuben_moku/last_time", time());
	who->move(this_object());
	this_object()->set("player", who);
	call_out("end_fuben_moku", 3600, who, this_object());
	init_player(who);
	write("��ս��ʼ������\n");
	
	return 1;
}

void end_fuben_moku(object me, object moku)
{
	if (sscanf(base_name(environment(me)), __DIR__"%*s"))
	{
		restore_status(me);
		me->move("d/city/kedian");
		tell_object(me,HBRED+HIY"��սʱ�䵽���㱻�������ݿ͵�\n"NOR);
	}
	destruct(moku);
}

private void init_player(object me)
{
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
    me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set("backup/condition", me->query_condition());
    me->clear_condition();
}

int check_out(object me)
{
    object ob;
    mapping my;
    string msg;
    string room;

    room = base_name(environment(me)) + ".c";
    if( room !=  __FILE__)
    {
            return 0;
    }
	
    my = me->query_entire_dbase();
    my["eff_qi"] = my["max_qi"];
    my["eff_jing"] = my["max_jing"];
    my["qi"] = 1;
    my["jing"] = 1;

    tell_object(me, HIR "\n�������ǰһ��ģ��...�������ˣ�\n" NOR);
    if( ob = me->query_last_damage_from() )
            msg = WHT "\n$N��" + ob->name(1) + "������ˣ��Ǳ����ӣ�\n\n" NOR;
    else
            msg = WHT "\n$N�������ˣ��Ǳ����ӣ�\n\n" NOR;

    message_vision(msg, me);

    restore_status(me);
    me->move("d/city/kedian");
    message("vision", "һ����Ӱٿ�Ĵ��˳������漴���ǡ�ž����"
            "һ�����ͼ�" + me->name() +"ˤ���˵��ϣ�һ��������"
            "������ӡ�\n", environment(me), ({ me }));
    tell_object(me, "�������У�����ñ���������������"
                "���ص�ˤ���˵��ϡ�\n");
    if( !living(me) )
            me->revive();

    return 1;
}


void restore_status(object me)
{
	mapping cnd;
	string *ks;
	int i;
	
    me->delete_override("unconcious");
    me->delete_override("die");
    me->clear_condition();
    cnd = me->query("backup/condition");
    if (! mapp(cnd)) return;
    
	ks = keys(cnd);
	for (i = 0; i < sizeof(ks); i++)
		me->apply_condition(ks[i], cnd[ks[i]]);
    me->receive_damage("qi", 0);
}