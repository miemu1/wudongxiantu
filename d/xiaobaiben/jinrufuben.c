// Room: /city/wumiao.c
// YZC 1995/12/04

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }
private void restore_status(object me);
private void init_player(object me);
void create()
{
	set("short", "��������");
	set("long", @LONG
�����ǽ��븱���ĵط�
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_learn", "1");
	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_sleep_room", "1");
	set("valid_startroom","1");
	
	set("objects", ([
   
			 __DIR__"qiandao" : 1,
	

	]));
	set("action_list", ([
		
	    "ÿ����ս�����Σ�" : "tiaozhan met",//��ͼ���ͽ�����ʾ
	
	]));

	
	setup();
}

void init()
{

	add_action("do_tiaozhan","tiaozhan");
	//add_action("get_gift","getgift");
}

int valid_leave(object me, string dir)
{
	if (dir == "northwest" && ! userp(me) && ! me->is_chatter())
		return 0;
	return ::valid_leave(me, dir);
}



int do_tiaozhan(string arg)
{
object me=this_player();
object competitionroom,npc;
int GMT = time();
	string d, dd,times,timess;
	int h, s;
	times = ctime(GMT);
	d = times[0..2];//����
if (!arg)
return 1;
//��սÿ�սӿڣ�������ַ���д��
 
 if (arg=="met")//����ָ��
  {
  timess = ctime(me->query("fuben/met"));//���
  dd=timess[0..2];//ʱ������
  me->delete_temp("met");
//if (time() > me->query("fuben/met")&&d!=dd)
me->set("fuben/met",time());//������ս����ʱ��
//else
//return notify_fail("������Ѿ���ս���ˡ�\n");//����������ʾ
if (me->query("tiaozhancishu")>2)
return notify_fail("������Ѿ���ս���ˡ�\n");//����������ʾ

if (objectp(competitionroom= new("/d/xiaobaiben/fangjian"))&&objectp(npc=new("/d/xiaobaiben/npc/npcshuxing")))//��ȡ��ͼ ��ȡnpcλ��
//competitionroom->set("exits/east","/d/city/wumiao");//�˳��ص�
tell_object(me,HBRED+HIY"��ս��������ʱ��Сʱ��\n"NOR);//������ʾ
me->move(competitionroom);//��ȡ�õ�ͼ���ɸ���
npc->move(competitionroom);//��ȡ��npc���ɸ���
npc->move(competitionroom);//��ȡ��npc���ɸ���
me->add("tiaozhancishu",1);
me->set_temp("zhuangtai",me->query_skill("force",1));//������ս����ʱ��
call_out("end_competition",1800,me,competitionroom);//ʱ��1����Ϊ��Сʱ
}
init_player(me);
return 1;

}

void end_competition(object me,object competition)
	{
	if (!objectp(me)||!objectp(competition))
	return;
	if (environment(me)->query("fuben"))
	{
	/*
	if (room1 = ) {//�����������
			if (sscanf(base_name(environment(me)), "/d/jingcheng/wanan-si/%*s"))
	*/
	me->move("d/city/kedian");//ʱ�䵽�����뿪��ͼ
	me->delete_temp("fuben/met");
	me->delete_temp("zhuangtai");
	tell_object(me,HBRED+HIY"��սʱ�䵽���㱻�������ݿ͵�\n"NOR);
	}
	destruct(competition);
	}


	private void init_player(object me)//��������
{
        me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
        me->set_override("die", (: call_other, __FILE__, "check_out" :));

        me->set_temp("backup/killer", me->query_killer());
        me->set_temp("backup/want", me->query_want());

        me->set("backup/condition", me->query_condition());
        me->clear_condition();

}

int check_out(object me)//��������
{
        object ob;
        mapping my;
        string msg;
        object room;

        room = environment(me);
        if (!room->query("fuben"))
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

private void restore_status(object me)//���״̬
{
        object *inv, obj;
        mapping cnd;
        string *ks;
        int i;
        me->delete_override("unconcious");
        me->delete_override("die");
        me->remove_all_enemy(1);
        me->remove_all_killer();
        me->clear_condition();
        me->receive_damage("qi", 0);
}
