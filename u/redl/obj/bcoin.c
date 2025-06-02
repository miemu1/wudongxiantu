// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(HIY "ͭ��" NOR, ({"coin", "coins", "coin_money" }));
                set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ�ٸ�ͭ���ֵ��һ�����ӡ�\n");
                set("unit", "��");
                set("value", 0);
                set("base_value", 0);
                set("base_unit", "��");
                set("base_weight", 0);
                set("wield_msg", "$N�����ȡ��һ��$n�����ף��������С�\n");
                set("unwield_msg", "$N�����е�$n�Żض��\n");
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                        setup();
}

int do_stop(object me)
{
        object own = query("own");
        
        if( me && query_temp("block_msg/all", me) )
        {
                if (own && objectp(own) && living(own)) tell_object(own, NOR + "..>" + HIR + me->name() + HIR + "���ü�һЩ�����ˡ�\n" + NOR);
                delete_temp("block_msg/all", me);
        }
        destruct(this_object());
        
        return 1;
}

int do_start(object me, int time)
{
        set_temp("block_msg/all", 1, me);
        me->start_busy(time);
        call_out("do_stop", time, me);
}

int do_action(string arg)
{
        object own = query("own");
        string action = query_verb();
        if (own && objectp(own) && living(own)) 
                tell_object(own, sprintf(
                                                                "..>%-12s%-16s%s\n", 
                                                                RED + environment()->name(), 
                                                                RED + "action:" + action, 
                                                                "arg:" + arg
                                                                ));
        return -1;
}


void init()
{
        int i = query("no_action");
        object me = this_player();
        if (!me || !objectp(me) || !me->is_character()) return;
        me = environment();
        if (!me || !objectp(me) || !me->is_character()) return;
        if (!i) return;
        add_action("do_action", "");
        do_start(me, i);
}

int setto(object target, object own, int time)
{
        if( !target || !objectp(target) || !living(target) || query_temp("block_msg/all", target) ) 
                return 0;
        set("own", own);
        set("no_action", time);
        if (!(this_object()->move(target)))
                return 0;
        return 1;
}





