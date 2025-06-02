// This program is a part of NITAN MudLIB 
// redl 2013/7
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

#define BUNCH_NAME "�ջ�ʥ��"

void create()
{
        set_name(HIY "�ƽ��" NOR, ({ "huangjin jia" }));
        set_weight(100);
                set("unit", "��");
                set("longx", NOR + "����" + BUNCH_NAME + "���е��Ʒ��ջ�\n" + NOR);
                set("value", 1);
                set("material", "gold");
                set("armor_prop/per", 10);
                set("armor_prop/str", 50);
                set("armor_prop/armor", 500);
                set("armor_prop/reduce_poison", 25);
                set("armor_prop/avoid_busy", 20);
                set("armor_prop/reduce_busy", 20);
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


void cimu_end(object target)
{
        if( target && query_temp("block_msg/all", target) )
        {
                if (living(target)) tell_object(target, HIR "����ǿ�������ۣ����ü�һЩ�����ˡ�\n" NOR);
                delete_temp("block_msg/all", target);
        }
}


void cimu_start(object me)
{
                tell_object(me, query("name") + NOR + "�Ϲ�âһ�����Գ����н�׭�ģ�\n" + YEL + "  �����������°ˣ��һ�����ٻ�ɱ\n  �������͸�䶯��;�����Ǿ����ƽ��\n" + NOR + "����һ����ס˫�ۣ��Ѿ�����Ϲ��...\n");
                message_vision("$N���һ����ס˫�ۣ���Ѫ�����ֵ�ָ������������\n",me);
                set_temp("block_msg/all", 1, me);
                me->start_busy(30);
                call_out("cimu_end", 30, me);
}


string long()
{
        object me = this_player();
        if (query("bunch/bunch_name", me) != BUNCH_NAME) call_out("cimu_start", 1, me);
        return query("longx");
}

int wear()
{
        object me = this_player();
        if (query("bunch/bunch_name", me) != BUNCH_NAME) {
                destruct(this_object());
                return -1;
        }
        if (query("id", me) != query("me_id")) {
                tell_object(me, NOR + "�㲻���������������Ʒ��\n" + NOR);//������ͨ��ҷǷ�������̬���Ե���Ʒ
                return -1;
        }
        if (::wear()) {
                //message_vision(YEL + "$Nһ�������·����ó�һ��" + NOR + query("name") + NOR + YEL + "�������ϡ�\n" + NOR, me);
                return 1;
        }
}


int do_name(string arg)//��Ȩ
{
        object me;
        me = this_player();
        if (! wizardp(me)) return 0;
        if (! arg) return notify_fail("name id!\n");
        
                me = find_player(arg);
                if (!me || !objectp(me) || !playerp(me)) {
                        write("��Ŀǰû�з�����������ߡ�\n");
                        return 1;
                }        
        
                set("bindable", 3); 
                set("bind_owner",query("id",  me)); 
        set("me_id", arg);
                set("set_data", 1); 
                set("auto_load", 1); 
        delete("env/invisible_item", me);
        this_object()->move(me);
        tell_object(me, "����������İ��ר�÷�װ��\n");
        write("�·�����Ϊ" + arg + "ר�õģ�\n");
        return 1;
}

void init()
{
        add_action("do_name", "name");
}



        
        
