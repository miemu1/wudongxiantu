// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h>
inherit ITEM;

void create() 
{ 
              set_name(NOR HIY "��" HIC"����"NOR, ({"door", "cang men"}) ); 
              if( clonep() ) {
                      destruct(this_object());
              }
              else { 
                        set_weight(100000000000);
                set("long", NOR "���ǽ���İ��ţ���֪��ͨ����������и�Բ��״�Ļ��أ�����(touch)���ԣ�\n" NOR);
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
              } 
              setup(); 
} 

int is_attacker(object me)
{
        object *attackers;
        attackers = query("attackers");
        if (!attackers || !sizeof(attackers)) return 0;
        if (member_array(me, attackers)==-1) return 0;
        return 1;
}

int do_touch()
{
        object *attackers;
        object me = this_object();
        object who = this_player();
        object fu;
        int tele_num;
        
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
        
        message_vision(NOR CYN "$N��ת���������ϣ�����ȥ��Ť�����ϵ�Բ����\n" NOR, who); 
        addn("neili", -100000, who);
        addn("jingli", -50000, who);
        addn("touch_num", 1, me);
        for (int i = 0; i<9; i++)
                if (query("touch_num", me) > 16 << i)
                        set("tele_num", i, me);
        tele_num = query("tele_num", me);
        if (tele_num>0) {
                message_vision(NOR HIW "$N" HIW "�Ͻ���������Գ�һ���֣���" + NOR YEL + ({"","��","��","��","��","��","��","��","��","��","��"})[tele_num] + HIW "����" + ((!random(5)) ? (NOR + " (push)?"):"") + "\n" NOR, me); 
                if ( !random(200) && (random(who->query_kar())>20) && ((tele_num -1 ) > query("drop_num/fu", me))) {
                        addn("drop_num/fu", 1, me);
                        message_vision(NOR HIW "$N" HIW "duang�ص���һ������...\n" NOR, me); 
                                        fu = new("/u/redl/teleport/npc/obj/qkfz");
                                        fu->move(environment(me));                      
                }
                
        } else {
                tell_object(who, NOR "Բ������һ�£��ƺ��ӰѾ�����һֱ����ȥ��\n" NOR); 
        }
        
        attackers = query("attackers");
        if (!attackers || !sizeof(attackers)) attackers = ({});
        if (!is_attacker(who)) {
                attackers += ({who});
                set("attackers", attackers);
        }
        //DEBUG_CHANNEL(query("touch_num", me));        
        return 1;
}

int do_push()
{
        object me = this_object();
        object who = this_player();
        int tele_num;
        
        tele_num = query("tele_num", me);
        if (tele_num<1) {
                tell_object(who, NOR "�������Ʋ��ţ�����ʲô��ӦҲû�С�\n" NOR); 
                return 1;
        }
        message_vision(NOR HIC"\n$N" NOR HIC "ʹ��һײ" "$n" HIC "������һ����֪����ȥ����\n\n" NOR, who, me); 
        who->move(get_object("/u/redl/teleport/yuanjiang/chuan7" + (string)tele_num));
        return 1;
}

void init()
{
        object me = this_player();
        if (!playerp(me)) return;
        add_action("do_touch", "touch"); 
        add_action("do_push", "push"); 
}


