// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h>
inherit ITEM;

void create() 
{ 
              set_name(NOR HIY "��" HIW"����"NOR, ({"box"}) ); 
                        set_weight(100000000000);
                set("long", NOR "���ǽ�������ı��䣬��(open)���ԣ�\n" NOR);
                set("unit", "��");
                set("value", 1);
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                set("unique", 1);
                set("no_pawn", 1);
              setup(); 
} 


int do_touch()
{
        object trap;
        object me = this_object();
        object who = this_player();
        
        if (who->is_busy())
        {
                tell_object(who, NOR BUSY_MESSAGE NOR); 
                return 1;
        }
        else if (random(3))
                who->start_busy(1);     
                
        if (query("neili", who)<1000000) {
                tell_object(who, NOR "���������㡣\n" NOR); 
                return 1;
        }
        if (query("jingli", who)<500000) {
                tell_object(who, NOR "�㾫�����㡣\n" NOR); 
                return 1;
        }
        
        message_vision(NOR CYN "$N��ת���������ϣ�����ȥ�����ӵĶ��ǡ�\n" NOR, who); 
        addn("neili", -100000, who);
        addn("jingli", -50000, who);
        addn("touch_num", 1, me);
        if (query("touch_num", me) < 10 || 
                query("touch_num", me) < random(500)) {
                        tell_object(who, NOR "���Ӷ���һ�£��ƺ���Ҫ�����ӰѾ���\n" NOR); 
                        return 1;
                }
        
        tell_object(who, HIW "�����ص�ը��������Ԫ��������ɢ����(xi)��һ��������������зɽ���������Ͻ�������������һ����\n" NOR);
        addn("yuan_ci_num", random(6)+ 3, environment(me));
        CHANNEL_D->channel_broadcast("news", HIG "��˵" + HIC + query("name", who) + HIG + "�ڽ���õ���һ��" HIY "�������"HIG"��");
        set_temp("jinchuan/iyca", 1, who);
        "/u/redl/teleport/ailao"->yuanci_attack(who);
        set_temp("jinchuan/iyca", 1, who);
        GIFT_D->delay_bonus(who, ([ "exp" : 7500000, "pot" : 2500000, "mar" : 1000000, "prompt" : "�������¹������֮��"]));
        //destruct(me);
        delete("touch_num", me);//����
        me->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        trap = new(__DIR__"trap");
        trap->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        trap = new(__DIR__"trap");
        trap->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        trap = new(__DIR__"trap");
        trap->move(get_object("/u/redl/teleport/yuanjiang/chuan" + (string)random(50)));
        return 1;
}

void init()
{
        object me = this_player();
        if (!playerp(me)) return;
        add_action("do_touch", "open"); 
}


