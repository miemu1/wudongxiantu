#include <ansi.h>
inherit ROOM;
//��ѽ��븱������
int cs = 1;
void create()
{
	set("short", "��Զ");
	set("long", @LONG
�����ǹ���פ���ľ������򡣳Ǹߺӿ��ر�ɭ�ϣ���¥�ϲ����д���
�Ĺٱ�פ�����������м��ź��»��ڣ��������ϡ������Լ����ٱ����ڼ��
�������˵���Ʒ����ʱ��������߳��֮����
LONG );
	set("exits", ([
//		"northeast" : __DIR__"road4",
		"south"     : __DIR__"ningyuan",
	]));
		set("action_list", ([
		HIM"��̬����"NOR:"ask_job 1",
	]));	 
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	setup();
}

void init()
{
    add_action("ask_job","ask_job");
}

int ask_quest()
{
	object me = this_player();
	string str;
	mixed *local,*last;
	int times;
	int ok =0,i;
	object *ob_list,room;
	int k;
	
	if (userp(me)) {
		if (me->query("fuben/jinbing1")) {
		ob_list = children("/adm/daemons/fuben_jinbing1");
		for(i=0; i<sizeof(ob_list); i++)  {
		if (ob_list[i]->query("id") == me->query("id")) {
		if (room = find_object(ob_list[i]->query("enter")))
		if (me->move(room))
			tell_object(me, HIR"ϵͳ��⵽���ϴεĸ�����δ����\n"NOR);
			return 1;
			}
		}
	}
		local = localtime(time());
		if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
				ok = cs;
		}
		last = localtime(me->query("fuben/jinbing1/times"));
		times = me->query("fuben/jinbing1/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/jinbing1/mun",0);
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "�����Ѿ��������Ѿ����"+(2+ok)+"���ˣ����������ɡ�"NOR"\n");
			return 1;
		}
		tell_object(me, str+"\n");
	}
	return 1;
}

int ask_job(string arg)
{
	object obj, me=this_player();
	object fb_room, *ob;
	int i, ok=0;
	int times;
	mixed *local,*last;
	string data;

	if (!arg || (arg !="1" && arg !="2" && arg !="3")) {
		ask_quest();
		return 1;
	}
	if (to_int(arg) < 1 || to_int(arg)>3) {
		tell_object(me, "�����ʲô��"NOR"\n");
		return 1;
	}
	if (me->query_condition("killer")){
		tell_object(me, "����ɱ�˷�?��"NOR"\n");
		return 1;
	}
        if( me->query("eff_qi")<me->query("max_qi") )
               return notify_fail("����������ˣ����ʺϸ�����\n");

        if( me->query("eff_jing")<me->query("max_jing") )
               return notify_fail("����������ˣ����ʺϸ�����\n");
               	
	ob=deep_inventory(me);
	for (i=0;i<sizeof(ob);i++) {
		if (userp(ob[i])) {
			tell_object(me, "��֧����ӣ�\n");
			return 1;
		}
	}

	me->delete_temp("ask_no");

	local = localtime(time());

	//����ṩһ�ν������
	if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
			ok = cs;
	}
		last = localtime(me->query("fuben/jinbing1/times"));
		times = me->query("fuben/jinbing1/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/jinbing1/mun",0);
			/*
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "�����Ѿ��������Ѿ����"+(2+ok)+"���ˣ����������ɡ�"NOR"\n");
			return 1;
	}*/
	data = (to_int(local[4])+1)+"-"+local[3];
	if (me->query("fuben/jinbing1/mun") <= cs)
	{
		me->set("fuben/jinbing1/times",time());
		me->add("fuben/jinbing1/mun", 1);
		me->add("fuben/jinbing1/"+data, 1);
		fb_room = new("/adm/daemons/fuben_jinbing1");//��
		fb_room->init(me);
		fb_room->set("id", me->query("id"));
		tell_object(me, HIR"�����ڽ�����̬��������"NOR"\n");
	} else 
		tell_object(me, "��������������Ѿ�û����\n");
	return 1;

}