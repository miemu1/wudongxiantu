// This program is a part of NITAN MudLIB 
// redl 2013/5
// ��սʱ��Ʒ��������ȴ

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"��"HIY"��"HIW"ľ" NOR, ({"mu"}));
                set("nj", 30);//60 nt��2nt�ⶾfullһ��
                set("longx",  
HIK 
"(                          �����޵Ĵ�˵\n"
"    �����޽�Ϊ���ޣ��԰������ӣ������뷲�����죬����ֲ�滨�����ҩ��\n"
"�Ȼ��������ͬ�������������ޡ�\n"
"    �����ޣ����ԣ���ɫ����ȡ���������֬���������㣬ü��������ɰ�롣\n"
"������ɫ��ǳ�����٣�ֱ����졢���졢ī�ڣ���������֮��\n"
"    ��������ԡ�𺣣���Ϊһ�ؿ�ľ��Ի����ľ����ľ�˷�����֮���ǣ��ɽ�\n"
"����֮�����罫ľ�������У���ҩ�ݡ����������֮����¶�β�֮��һ�º��\n"
"ľ����ƻ��ʵ������ٶ��£���ɫ�ʵ���ľ�ϳ�����֫�������£�ľ����\n"
"�٣��Ƴ����ˣ��ȶ�ľ�ʱ��ᣬ�׶���覣������£�ľ���ϣ������޳�������\n"
"�޳���֮ʮ���ڣ���ֿ��֮ѪΪ��ÿ���֮�������꣬�������ܱ���ǰ�����䡣\n"
"����������޲�ͨ���ʳ���ۡ����꼰����ҩ��Ϊʳ�����ɳ�����죬����\n"
"�������α�������С�����죬��ʱ����������������ϻۣ��˺�ʮ���������\n"
"С��һ�ֱ꣬�����ꡣ\n"
"    ������������֮��������޲���쳾�������������ɳ����������ɣ���\n"
"���߱���Ĳݣ�������٣�ԡ��𺣣������ֻء��������ˣ�ʮ�ս��緲��һ\n"
"�ֱ꣬�������ֻػ�Ϊ��ľ���������أ�ľ��ɫ�����ڣ�����ҩ����ǿ��\n"
"    ������ɫ��������Ѱ����������������֮�����һ��Ϊ�����������Ӳ�\n"
"������֮�٣�����������֮���١�)\n"
NOR);
                //set("base_unit", "��");
                //set("base_value", 150000000);
                //set("base_weight", 800);
                set("value", 1);
                set("weight", 800000);
                set("unit", "��");
                //set("no_store", 1); 
                set("no_steal", 1); 
                set("no_beg", 1); 
                set("set_data", 1);  
                set("auto_load", 1);  
        setup();
}

string long()
{
        return HIG "����һ�������޵��Ź���������ľ - �;öȣ�"+ HIC + query("nj") + HIG + 
                        "\n��֮(smell mu)  �ɽ��򶾳�����ҽĿäԭ�ظ��\nʳ֮(eat mu)    ����ֱ�ӵ������õ�ʮ��������(���������;ö�)��\n" NOR + query("longx");
}

void init()
{
        add_action("do_smell", "smell");
        add_action("do_eat", "eat");
}

int do_smell(string arg)
{
    mapping my;
        object me = this_player();
        
        if (! arg || arg != "mu") {
                tell_object(me, "��Ҫ��ʲô������\n");
                return 1;
        }
        if (me->is_busy()) {
                tell_object(me, "����æ�����������˵�ɣ�\n");
                return 1;
        }
     if (query_temp("durg_time/mu", me) > time()) {
         tell_object(me, "����ôƵ��������Ϊ����������\n"); 
         return 1;
     }

/*
        if (me->is_fighting()) {
                tell_object(me, "�����ڴ��û��ȥ��ľͷ��\n");
                return 1;
        }
*/
        
        me->start_busy(1);
        delete_temp("block_msg/all", me);
        my = me->query_entire_dbase();
        my["jing"]   = my["eff_jing"]   = my["max_jing"]; 
        my["jingli"] = my["eff_jingli"] = my["max_jingli"]; 
        my["qi"]     = my["eff_qi"]     = my["max_qi"]; 
        my["neili"]  = my["max_neili"];
        me->clear_condition();
        me->clear_weak();
              if( query_temp("block_msg/all", me) ) { 
                              tell_object(me, HIR "������Ĩ������ǰ����Ѫ���ܿ����ˡ�\n" NOR); 
                              delete_temp("block_msg/all", me); 
              } 
        //me->full_self();
     set_temp("durg_time/mu", time() + 60, me);

        message_vision(YEL + "$Nȡ��һ��"+ query("name") + YEL +"���ڱǶ������ᣬ�����������\n" + NOR, me); 
        addn("nj", -1);
        if (query("nj") < 1) {
                message_vision(NOR + "$N�����"+ query("name") + NOR +"΢���������ֻ���ɢ�ˡ�\n" + NOR, me); 
                destruct(this_object());
        }
        return 1;
}


int do_eat(string arg)
{
        object me = this_player();
        
        if (! arg || arg != "mu") {
                //tell_object(me, "��Ҫ��ʲô������\n");
                return 0;
        }
        if (me->is_busy()) {
                tell_object(me, "����æ�����������˵�ɣ�\n");
                return 1;
        }
        if (me->is_fighting()) {
                tell_object(me, "�����ڴ��û��ȥ��ľͷ��\n");
                return 1;
        }
        if (query("nj") != 30) {
                tell_object(me, "���������ľͷ�������ˣ�\n");
                return 1;
        }
        
        me->start_busy(1);
        set("age", 18, me);
        set("mud_age", (18 - 11) * 518400, me);
        message_vision(YEL + "$N�ó�һ��"+ query("name") + YEL +"����ɺڷۣ���ͷ������ȥ��\n" + NOR +
                                                 "$N��ȫ������������죬Ƥ��Ҳ����Ť����Ƭ��֮������һ�ٶ����������Եú����ᰡ~~~\n" + NOR, me); 
        message_vision(NOR + "$N�����"+ query("name") + NOR +"΢���������ֻ���ɢ�ˡ�\n" + NOR, me); 
        destruct(this_object());
        return 1;
}


