// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h>
inherit NPC;

int get_help()
{
        write( CYN + query("name") + CYN + "˵�������������й���ӵ��������Ľ𵤣��м�������ǻۺ���Ϊ��\n"+ NOR); 
        return 1;
}

int get_help2()
{
        write( CYN + query("name") + CYN + "˵����������̫�����֣������ޱȡ�������н�����ң����Ե������������\n"+ NOR); 
        return 1;
}

int get_help3()
{
        write( CYN + query("name") + CYN + "˵�������ֲշ�Ϊ�������������춡���Ҽס�ʮ��������touch���ſ��Դӹ��ƶ����ף�����ǰ�����Զ�PK�����Կ��Ǻ����ӿ졣\n"+ NOR); 
        return 1;
}

int get_help4()
{
        write( CYN + query("name") + CYN + "˵�����𴬵�ͼ�޴���maphere -m�ȵ�����maphereҪ����ԶЩ����������ڴ��ض��ǲ������ڡ�\n"+ NOR); 
        return 1;
}

int get_help5()
{
        write( CYN + query("name") + CYN + "˵����Ԫ����������Ԫ�ŵ����ı�����ϣ��ڽ���ʹ��xiָ����Ի��Ԫ������������ʮ����������ḻ��\n"+ NOR); 
        return 1;
}

int get_help6()
{
        write( CYN + query("name") + CYN + "˵����Ԫ�ŵ����Ǹ����ܼ�����taoism�ϵ����������ѧ���������뵶���ʹ���þ���ʱ������У�С��������ʦ�ó��˵���\n"+ NOR); 
        return 1;
}

int get_help7()
{
        write( CYN + query("name") + CYN + "˵�����������СԪ������ը�ǵ�������ģ����������ܵ��Ľ𴬴�Ԫ�����ۻ��˺��������Ǽ����¡�\n"+ NOR); 
        return 1;
}

int get_help8()
{
        write( CYN + query("name") + CYN + "˵����������Ҷ�ñ����Һ�ˮ�������ѷ���������ڵ��ټ�����С�ĵ���Ŷ��\n"+ NOR); 
        return 1;
}

int get_reward()
{
                int amount;
        object room, me, obj, *inv;
        me = this_player();
        
        if(me->is_busy()) {
                        write(NOR "����æ���ء�\n" NOR);
                        return 1;
        }
        me->start_busy(1);

        if( query("online_time", me) < 86400 * 7){
                tell_object(me,CYN + query("name") + CYN + "˵�������������䶼û�г���һ�ܣ���С�Űɣ�\n"+ NOR); 
                return 1;
        }      
        
        amount = query("combat_exp", me);
        if( amount < 1000000000){
                tell_object(me,CYN + query("name") + CYN + "˵������������Ϊ��ȥ�ܸ�ʲô��\n"+ NOR); 
                return 1;
        }
        
        if( objectp(query_temp("is_riding", me)) ){//���з����Ѿ������˱���ҽ������Լ��ܶ���������
                tell_object(me,CYN + query("name") + CYN + "˵���������ȣ�\n"+ NOR); 
                return 1;
        }      
        
        if( query("weiwang", me) < 1000000){
                tell_object(me,CYN + query("name") + CYN + "˵�����������̫���ˣ���ֻ�ͳ������������\n"+ NOR); 
                return 1;
        }
    
        room = environment(this_object());
        if (query("blv", room) < 9){
                tell_object(me,CYN + query("name") + CYN + "˵����������̫���ˣ������Ѿ���ʼ��\n"+ NOR); 
                return 1;
        }
        
      if( query("gcjinchuan_time", me) >= query("gcjinchuan_time", room) ) 
        {
                tell_object(me,CYN + query("name") + "˵����������ع���Ƶ���ˣ�\n"+ NOR); 
                return 1;
       }
        //DEBUG_CHANNEL("player gcjinchuan_time��" + (string)query("gcjinchuan_time", me));
        //DEBUG_CHANNEL("room gcjinchuan_time��" + (string)query("gcjinchuan_time", room));
        
                addn("weiwang", -30000, me);
                tell_object(me, NOR "�㱻�۳�����㽭��������\n"+ NOR); 
                message_vision(append_color(NOR + CYN + query("name") + CYN + "һ�����䣬$N" + NOR + CYN + "����������Ԫ��������\n" + NOR, CYN), me);
                set("gcjinchuan_time", query("gcjinchuan_time", room), me);
                me->move(get_object("/u/redl/teleport/yuanjiang/jiaban"));
                CHANNEL_D->channel_broadcast("rumor", "��˵" + query("name", me) + "�Ѿ��ϸ�Ԫ���Ĺ�ɽ𴬶ᱦ��\n");
        return 1;
}      

void create()
{
        set_name( "֣����" , ({ "zheng dianxian", "zheng" }));
        set("long", @LONG
���˴�������������ˣ�Ԫ���ᱦ�ĳ����ߡ�
LONG);
        set("gender", "Ů��" );
        set("title", NOR HIC "�������" NOR);
        set("age", 45);
        set("level", 200);
        set("attitude", "friendly");
        set("max_jing", 500000000);
        set("max_qi", 500000000);
        set("max_jingli", 500000000);
        set("jingli", 500000000);
        set("max_neili", 500000000);
        set("neili", 500000000);
        set("jiali", 5000000);
        set("str", 200);
        set("int", 200);
        set("con", 200);
        set("dex", 200);
        set("combat_exp", 120000000000);

        set("inquiry", ([
                "��ɽ�" : (: get_help :),
                "��ɽ�" : (: get_reward :),
                "boat" : (: get_reward :),
                "����" : (: get_help2 :),
                "���ֲ�" : (: get_help3 :),
                "��ͼ" : (: get_help4 :),
                "Ԫ����" : (: get_help5 :),
                "Ԫ�ŵ���" : (: get_help6 :),
                "����" : (: get_help7 :),
                "box" : (: get_help7 :),
                "������Ҷ" : (: get_help8 :),
                "leaf" : (: get_help8 :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}


int push_down(object me)
{
        if (!me) return 1;
        if (!environment(me)) return 1;
        if (environment(me)!=environment(this_object())) return 1;
        
        message_vision(append_color(NOR + CYN + query("name") + CYN + "һ�����䣬$N" + NOR + CYN + "�Ǳ�����������ȥ��\n" + NOR, CYN), me);
        me->move(query("exits/out", environment(this_object())));
        return 1;
}

void init()
{
        object me = this_player();
        
        //remove_call_out("push_down");
        //call_out("push_down", 60, me);
}


int accept_object(object me, object obj)
{
        object room;
        int *t;
        
        if (me->is_busy())
        {
                tell_object(me, NOR BUSY_MESSAGE NOR); 
                return 0;
        }
        else 
                me->start_busy(2);
                
        if (!query("is jin zhu", obj)){
                tell_object(me, NOR CYN + query("name") + CYN + "ҡͷ����˵������ֻ��Ҫ���롣\n" NOR); 
                return 0;
    }

/*        if( query("online_time", me) < 86400 * 2){
                tell_object(me,CYN + query("name") + CYN + "˵�������������䶼û�г������죬��С�Űɣ�\n"+ NOR); 
                return 0;
        }      */
        
       t = TIME_D->analyse_time(TIME_D->query_real_time());
       if (t[1]>=19 && t[1]<21)
        {
                tell_object(me, NOR CYN + query("name") + "ҡͷ����������������֮�䲻����˽�˴��̡�\n"+ NOR); 
                return 0;
       }

        room = environment(this_object());
        if (query("blv", room)){
                tell_object(me, NOR CYN + query("name") + CYN + "˵����������̫���ˣ������Ѿ���ʼ��\n"+ NOR); 
                return 0;
        }
        
      if( query("gcjinchuan_time", room) && //�����������һ���ý����ȥ����Ҳ������CD����
        query("gcjinchuan_time", me) >= query("gcjinchuan_time", room) ) 
        {
                tell_object(me, NOR CYN + query("name") + "˵����������ع���Ƶ���ˣ�\n"+ NOR); 
                return 0;
       }
       
        tell_object(me, NOR CYN + query("name") + CYN + "��ͷ����˵�������Դ�Ƭ�̡�\n" NOR); 

                message_vision(append_color(NOR + CYN + query("name") + CYN + "һ�����䣬$N" + NOR + CYN + "����������Ԫ��������\n" + NOR, CYN), me);
                set("gcjinchuan_time", query("gcjinchuan_time", room), me);
                me->move(get_object("/u/redl/teleport/yuanjiang/jiaban"));
        
        room->cdeploy(me);
        return 1;
}



