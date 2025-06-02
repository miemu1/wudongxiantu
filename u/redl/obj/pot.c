// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <weapon.h>
#include <ansi.h>
#include <armor.h> 
inherit HANDS;

#define SK_ID "taishang-wangqing"

int check_dest(string msg, object me)
{
        if (! msg || msg == "") msg = "�ж���";
                if (query("amount") < 1) {
                        message_vision(YEL + "$Nһ��ƺ���"+ msg + "���ƺ�ȴವػ���һ����â�ƿ������������ȥ......\n" + NOR, me);
                        destruct(this_object());
                        return 1;
                }
                return 0;
}

int chkw()
{
        if (query("equipped") == "worn") return 1;
        return 0;
}
       
void chkd()
{
        if (!query("no_get")) {
                if (query("amount") < 1) {
                        if (playerp(environment(this_object()))) message_vision(YEL + "$N����ľƺ�һ�������ವػ���һ����â�ƿ������������ȥ......\n" + NOR, environment(this_object()));
                                else message_vision(YEL + "�ƺ�һ�������ವػ���һ����â�ƿ������������ȥ......\n" + NOR, this_object());
                        destruct(this_object());
                        return;
                }       
                
                        addn("amount", -1);
        }
        call_out("chkd", 8);
}

void init() 
{ 
        object me = this_player();
              add_action("do_drink","drink"); 
              add_action("do_ding","ding"); 
              add_action("do_zhan","zhan"); 
        if (wizardp(me) || query("id", me) == "redl" || query("couple/couple_id", me) == "redl") {
              add_action("do_setnoget","setnoget"); 
              add_action("do_setamount","setamount"); 
    }
} 

int do_setnoget()  
{
        if (!query("no_get")) set("no_get",1); 
                else delete("no_get"); 
        return 1;
}

int do_setamount(string arg)  
{
        if (! arg || arg == "") return notify_fail(NOR + "��Ҫ������ֵ������\n" + NOR); 
        set("amount",to_int(arg)); 
        return 1;
}

int can_force(object me, object victim)
{
        object where = environment(victim);
        
        if (!where || !objectp(where)) {
                tell_object(me, NOR + "���Ŀ���Ż�û�г�����\n" + NOR); 
                return 0;
        }
        if ((!wizardp(me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl") && (
                        query("no_fight", where) || query("sleep_room", where) || (playerp(victim) && !sscanf(base_name(where), "/d/pk/%*s"))
                                )) {
                tell_object(me, NOR  + query("name") + "һ���궯�����ܿ��ƽ����...\n" + NOR); 
                return 0;
        }
        return 1;
}

int do_ding(string arg)  
{
        object victim;
        object me = this_player();
        
        if (!chkw()) return notify_fail(NOR + "��װ������ʹ�ðɣ�\n" + NOR); 
        if (! arg || arg == "") return notify_fail(NOR + "��Ҫ����Ŀ���ID����\n" + NOR); 
        if ( me->query_skillo(SK_ID, 1) < 50 ) return notify_fail(NOR + "�㻹û������������ͨ��\n" + NOR);              
        
        victim = present(arg, environment(me));
        if (!victim || (victim == me || !living(victim) || !objectp(victim) )) return notify_fail(NOR + "��ѡ���Ŀ�겻�Ծ���\n" + NOR);    
        
    if (check_dest("��", me)) return 1;
    
    if (can_force(me, victim)) {
                set("last_opponent", me, victim);//             victim->kill_ob(me);
                message_vision(CYN + "$N������ȡ��һ��" + query("name") + CYN + "���������ϣ�" + query("name") + CYN + "��������һ��"+HIR+"��"+HIG+"��"+HIY+"��"+HIC+"��"+NOR+CYN+"��\n����һ����ü��Ŀ�������������"+HIW+"�׹�"+NOR+CYN+"��ֱ��ס$n"+NOR+CYN+"�����蹬��$n"+NOR+CYN+"��ʱ�Ժ��޷������ˡ�\n" + NOR, me, victim);
                victim->start_busy(75+random(16));
                __DIR__"table"->ding_zx(victim);
                set_temp("target_obj", victim);
                addn("amount", -20);
                me->start_busy(2+random(2));
        }
        
        return 1;
}

int do_zhan(string arg)  
{
        object victim, head, corpse, where;
        object *obs;
        int i;
        string msg;
        object me = this_player();

                        if(me->is_busy()) {
                                return notify_fail(NOR + "�㻹��æ����˵�ɣ�\n" + NOR);
                        }
        
        if (!chkw()) return notify_fail(NOR + "��װ������ʹ�ðɣ�\n" + NOR); 
        if ( me->query_skillo(SK_ID, 1) < 80 ) return notify_fail(NOR + "�㻹û������������ͨ��\n" + NOR); 
        if ((!arg || arg == "") && (!query_temp("target_obj"))) return notify_fail(NOR + "��Ҫ����Ŀ���ID���������ȶ�(ding)סһ��Ŀ�꣡\n" + NOR); 
        if (check_dest("ն", me)) return 1;
        
        if ((!arg || arg == "") && (query_temp("target_obj"))) {
                victim = query_temp("target_obj");
                if (!victim || (victim == me || !living(victim) || !objectp(victim) )) return notify_fail(NOR + "��ѡ���Ŀ�겻�Ծ���\n" + NOR);    
                if (can_force(me, victim)) {
                        message_vision(CYN + "$N��������" + query("name") + CYN + "����һҾ�����뱦��ת����\n" + NOR, me, victim);
                        where = environment(victim);
                        msg = query("name", victim);
                        set("last_opponent", me, victim);                       victim->kill_ob(me);
                        set_temp("die_reason", "��"+query("name",me)+"�ų��ƺ����ն�ɷɵ�ն��", victim);
                        victim->die();
                        corpse = present("corpse", where);
                                if (base_name(corpse) == "/clone/misc/corpse") {
                                        message_vision(CYN + "ֻ����"+HIW+"�׹�"+NOR+CYN+"��" + msg + NOR + CYN + "������һ�ƣ�ת�������촦����ͷʬ���Ȼ���¡�\n" + NOR, me);
                                        set("defeated_by", query("id", me), corpse);
                                        set("defeated_by_who", query("id", me), corpse);
                                        set("killed_by", query("id", me), corpse);
                                        head = new("/clone/misc/head");
                                        head->set_from(corpse);
                                        head->move(where);
                                } else {
                                        message_vision(CYN + "ֻ����"+HIW+"�׹�"+NOR+CYN+"��" + msg + NOR + CYN + "������һ�ƣ�������ת�˼�Ȧ����������޹�������\n" + NOR, me);
                                }
                        addn("amount", -30);
                        delete_temp("target_obj");
                        me->start_busy(2+random(2));
                }
                return 1;
        } else if (arg == "*") {
                if (me->query_skillo(SK_ID, 1) < 100) return notify_fail(NOR + "�㻹û������������ͨ��\n" + NOR); 
                if (!sizeof(obs = me->query_enemy())) return notify_fail(NOR + "��û����ս���С�\n" + NOR); 
                message_vision(CYN + "$N������ȡ��һ��" + query("name") + CYN + "���������ϣ�\n" + NOR, me);
                message_vision(CYN + "$N��������" + query("name") + CYN + "����һҾ�����뱦��������\n" + NOR, me);
                message_vision(CYN + query("name") + CYN + "��������һ��"+HIR+"��"+HIG+"��"+HIY+"��"+HIC+"��"+NOR+CYN+"������һ����ü��Ŀ�������������"+HIW+"�׹�"+NOR+CYN+"�Ĵ���ɨ...\n" + NOR, me);
                for (i = 0; i < sizeof(obs); i++) {
                        if( ! obs[i] ) continue;
                        if (! obs[i]->is_busy()) obs[i]->start_busy(3 + random(3));
                        msg = query("name", obs[i]);
                        if (!i) message_vision(CYN + "\n$N����" + query("name") + CYN + "ңңһ���֣����뱦��ת����\nֻ��һ��"+HIW+"�׹�"+NOR+CYN+"ٿ����" + msg + NOR + CYN + "ͷ��һ��..." + NOR, me);
                                else message_vision(CYN + "\n����ʯ�䣬�ǵ�"+HIW+"�׹�"+NOR+CYN+"������" + msg + NOR + CYN + "ͷ��һ��..." + NOR, me);
                        set("last_opponent", me, obs[i]);                       obs[i]->kill_ob(me);
                        set_temp("die_reason", "��"+query("name",me)+"�ų��ƺ����ն�ɷɵ�ն��", obs[i]);
                        obs[i]->die();
                        corpse = present("corpse", environment(me));
                                if (base_name(corpse) == "/clone/misc/corpse") {
                                        message_vision(HIW+"�׹�"+NOR+CYN+"����" + msg + NOR + CYN + "�Ĳ�����һ�ƣ�ת�������촦����ͷʬ���Ȼ���¡�\n" + NOR, me);
                                        set("defeated_by", query("id", me), corpse);
                                        set("defeated_by_who", query("id", me), corpse);
                                        set("killed_by", query("id", me), corpse);
                                        head = new("/clone/misc/head");
                                        head->set_from(corpse);
                                        head->move(environment(me));
                                } else {
                                        message_vision(HIW+"�׹�"+NOR+CYN+"����" + msg + NOR + CYN + "�Ĳ�����һ�ƣ�������ת�˼�Ȧ����������޹�������\n" + NOR, me);
                                }
                        addn("amount", -40);
                }
                me->start_busy(2+random(2));
                return 1;
        } else if (arg && me->query_skillo(SK_ID, 1) >= 120) {
                victim = present(arg, environment(me));
                if (!victim || (victim == me || !living(victim) || !objectp(victim) )) {//return notify_fail(NOR + "��ѡ���Ŀ�겻�Ծ���\n" + NOR);    
                foreach(object tob in objects()) {
                    if(tob->id(arg)) {
                        victim = tob;
                        break;
                    }
            }
                }
                if (!victim || (victim == me || !living(victim) || !objectp(victim) )) return notify_fail(NOR + "��������Ҳû�к��ʵ�Ŀ�꣡\n" + NOR);    
                if (can_force(me, victim)) {
                        where = environment(victim);
                        msg = query("name", victim);
                        message_vision(CYN + "$N�����ض���" + query("name") + CYN + "��ߵ�׵������뱦��������\n" + NOR, me);
                        message_vision(CYN + query("name") + CYN + "������"+HIR+"��"+HIG+"��"+HIY+"��"+HIC+"��"+NOR+CYN+"������һ����ü��Ŀ�������������"+HIW+"�׹�"+NOR+CYN+"��͸�����ס"+(stringp(where->short())?where->short():"ңԶ��")+NOR+CYN+"��"+NOR+CYN+msg+NOR+CYN+"...\n" + NOR, me);
                        message_vision(CYN + "����ͻȻ��������"+HIW+"�׹�"+NOR+CYN+"������һ����ü��Ŀ��ֱֱ��ס$N"+NOR+CYN+"...\n" + NOR, victim);
                        msg = query("name", victim);
                        set("last_opponent", me, victim);//                     victim->kill_ob(me);
                        set_temp("die_reason", "��"+query("name",me)+"�ų��ƺ����ն�ɷɵ�ն��", victim);
                        victim->die();
                        corpse = present("corpse", where);
                                if (base_name(corpse) == "/clone/misc/corpse") {
                                        message_vision(CYN + "ֻ����"+HIW+"�׹�"+NOR+CYN+"��" + msg + NOR + CYN + "������һ�ƣ�ת�������촦����ͷʬ���Ȼ���¡�\n" + NOR, where);
                                        message_vision(CYN + "ֻ����"+HIW+"�׹�"+NOR+CYN+"ٿ����ʧ��������"+HIW+"�׹�"+NOR+CYN+"������أ����е���һ��ͷ­��"+HIW+"�׹�"+NOR+CYN+"��������" + query("name") +NOR+CYN+ "��\n" + NOR, me);
                                        set("defeated_by", query("id", me), corpse);
                                        set("defeated_by_who", query("id", me), corpse);
                                        set("killed_by", query("id", me), corpse);
                                        head = new("/clone/misc/head");
                                        head->set_from(corpse);
                                        head->move(environment(me));
                                } else {
                                        message_vision(CYN + "ֻ����"+HIW+"�׹�"+NOR+CYN+"��" + msg + NOR + CYN + "������һ�ƣ�������ת�˼�Ȧ����������޹�������\n" + NOR, where);
                                        message_vision(CYN + "ֻ����"+HIW+"�׹�"+NOR+CYN+"ٿ����ʧ��������"+HIW+"�׹�"+NOR+CYN+"������أ�������ص�������" + query("name") +NOR+CYN+ "��\n" + NOR, me);
                                }
                        addn("amount", -100);
                        me->start_busy(2+random(2));
                }
                return 1;
        }
    
        return notify_fail(NOR + "�㻹û������������ͨ��\n" + NOR); 
}

       
int do_drink(string arg)  
{ 
                object me = this_player();
                string id = query("id", me);
                int lv;

                        if (! arg || (arg != "wine" && arg != "pot"))
                                return 0;
                
                        if (!chkw()) return notify_fail(NOR + "��װ������ʹ�ðɣ�\n" + NOR); 

              if( time()-query_temp("last_eat/redl_wine", me) < 2 )  
              { 
                      write("������Ȱ�..���Ǵ�������������..��\n");  
                      return 1;  
              } 


                    if (check_dest("��", me)) return 1;
                    
                        message_vision(YEL "$Nһ��ƺ����ȣ��ƺ�ȴ��ȴ�տ���Ҳ......\nֻ��Զ������һλ���´�ʷ������ʵ�켸�����$N��������һ�������ơ�\n$N���ֽ�������������ʱ�Ѿ����˸��׳��졣($N��" HIG "״̬�ָ���.." + NOR + YEL + ")\n" + NOR, me);
                        addn("amount", -10);

                                set_temp("last_eat/redl_wine", time(), me);  
                                set_temp("nopoison", 3,         me); 
                                if (!random(5)) me->improve_skill(SK_ID, 50000);
                                        else me->improve_skill(SK_ID, 10000);
                                
                                lv = me->query_skillo(SK_ID, 1);
                                if ( lv < 80 ) {
                                        write(CYN + "��о��������Ǻ�������Ͽڡ�\n" + NOR);  
                                        set("eff_jing",query("max_jing",  me),  me); 
                                        set("jing",query("max_jing",  me) / 2, me); 
                                        set("eff_qi",query("max_qi",  me), me); 
                                        set("qi",query("max_qi",  me) / 2, me); 
                                        set("jingli",query("max_jingli",  me) / 2,  me); 
                                        set("neili",query("max_neili",  me) / 2,  me); 
                                } else if ( lv < 120 ) {
                                        write(CYN + "��о��������һ������ζ�ӳ¡�\n" + NOR);  
                                        set("eff_jing",query("max_jing",  me),  me); 
                                        set("jing",query("max_jing",  me), me); 
                                        set("eff_qi",query("max_qi",  me), me); 
                                        set("qi",query("max_qi",  me), me); 
                                        set("jingli",query("max_jingli",  me),  me); 
                                        set("neili",query("max_neili",  me),  me); 
                                } else {
                                        write(CYN + "��о���Ʒ����������೤������\n" + NOR);  
                                        set("eff_jing",query("max_jing",  me),  me); 
                                        set("jing",query("max_jing",  me) * 2, me); 
                                        set("eff_qi",query("max_qi",  me), me); 
                                        set("qi",query("max_qi",  me) * 2, me); 
                                        set("jingli",query("max_jingli",  me) * 2,  me); 
                                        set("neili",query("max_neili",  me) * 2,  me); 
                                }
                                
                                if ( lv >= 50 ) write("��ͨ���˾ƺ���һ�ֳ�����ͨ������ʹ��(ding id)��ס��ǰ��Ŀ�ꡣ\n");  
                                if ( lv >= 80 ) write("��ͨ���˾ƺ���һ���м���ͨ������ʹ��(zhan)ն����ǰ����ס��Ŀ�ꡣ\n");  
                                if ( lv >= 100 ) write("��ͨ���˾ƺ���һ�ָ߼���ͨ������ʹ��(zhan *)ն����ǰȫ���ĵ��ˡ�\n");  
                                if ( lv >= 120 ) write("��ͨ���˾ƺ���һ���ռ���ͨ������ʹ��(zhan id)ն��Զ����ߵ�����Ŀ�ꡣ\n");  
                                if ( lv >= 100 ) {
                                        write("��ͨ����̫����������⣬һ�ھƽ�������о綾��\n");  
                                                me->clear_condition();
                                                me->stop_busy();
                                                me->clear_weak();
                                }

                        return 1;
                
} 



mixed hit_ob(object me, object victim, int damage_bonus)
{

    if (check_dest("��", me)) return 0;

        switch (random(10))
        {
        case 0:
                        addn("amount", -1);
                if (! query_temp("block_msg/all", victim)) {
                      victim->start_busy(3+random(2));
                      set_temp("block_msg/all", 1, victim);
                      call_out("cimu_end", 3+random(2), victim);
                          message_vision(HIY "$N��" + NOR + YEL + "�ƺ�" + HIY + "ʹ��ҡ�����£�Ȼ���ú����׼$n" + NOR + HIY + "������һ��...\n$n" + NOR + HIY + "⧲������±�" + HIR + "�Ҿ�" + NOR + HIY + "����һͷ��˫�����̻��������������ˣ�\n" NOR, me, victim);
                          return 0;
                }
                else {
                        message_vision(HIY "$N����Ծ�������" + NOR + YEL + "�ƺ�"+ HIY +"��â��������ȡͷ�������ǹ⣬����Ю�����Ծ�����$n" + NOR + HIY + "����...\n" NOR, me, victim);
                        return damage_bonus * (291 + random(10));
                }
        }
        return damage_bonus;
}



void cimu_end(object target)
{
        if( target && query_temp("block_msg/all", target) )
        {
                if (living(target)) tell_object(target, HIR "����ǿ�������ۣ����ü�һЩ�����ˡ�\n" NOR);
                delete_temp("block_msg/all", target);
        }
        return;
}

void create() 
{ 
              set_name(YEL"�ƺ�"NOR, ({"pot", "wine pot"}) ); 
              set_weight(1000); 
              if( clonep() ) {
                      destruct(this_object());
              }
              else { 
                      set("long", 
                      "    �������һ�Ѿƺ������ӵ���ɫ����������ž��ȵ����׹�ߡ��ʵ��ƴɷǴ�����������\n" +
                      "����ӡ�ż�����Ի��\n" + NOR +
                      "    "+HIW+BCYN+"��֮�����Ի����񣬾���������������" + NOR +
                      "\n    "+HIW+BCYN+"���޿����������������ܲ��ʰ���ͯ�ӡ�"+ NOR + "                  " + HIK +
                      "(redl 2012.11)\n\n" + NOR + 
                      "�㰵�Բ���������װ�ľƺú�(drink pot)��\n"
                      );  
                      set("unit", "��"); 
                      set("amount", 1100);
                      set("value", 10000);
                                      set("no_sell", "�ţ���������ı����أ���ô������...");
                                  set("no_put",1);   
                      set("no_steal",1);
                                      set("unique", 1); 
                                  set("rigidity", 8000);  
                                          set("material", "steel");
                set("armor_prop/str", 1500);
                set("armor_prop/int", 1500);
                set("armor_prop/con", 1500);
                set("armor_prop/dex", 1500);
                set("armor_prop/armor", 150000);
                //set("armor_prop/armor1", 150000);
                set("armor_prop/damage", 75000);
                //set("armor_prop/damage1", 75000);
                set("armor_prop/unarmed_damage", 75000);
                set("armor_prop/attack", 3000);
                set("armor_prop/defense", 3000);
                                set("armor_prop/research_times", 1000);
                set("armor_prop/research_effect", 300);
                set("armor_prop/practice_times", 1000);
                set("armor_prop/practice_effect", 300);
                set("armor_prop/learn_times", 1000);
                set("armor_prop/learn_effect", 300);
                set("armor_prop/derive_times", 800);
                set("armor_prop/derive_effect", 250);
                set("armor_prop/full_self", 80);
                set("armor_prop/reduce_poison", 100);
                //set("armor_prop/add_locked", 25);
                //set("armor_prop/avoid_locked", 50);
                set("armor_prop/fatal_blow", 50);
                set("armor_prop/add_skill", 180);
                set("armor_prop/avoid_die", 65);
                set("armor_prop/avoid_blind", 100);
                set("armor_prop/ap_power", 120);
                set("armor_prop/dp_power", 180);
                set("armor_prop/da_power", 80);
                set("armor_prop/avoid_busy", 80);
                set("armor_prop/reduce_busy", 80);
                set("armor_prop/through_armor", 40);
                set("armor_prop/add_freeze", 30);
                //set("armor_prop/add_burning", 100);
                set("armor_prop/add_forget", 20);
                set("armor_prop/add_busy", 50);
                //set("armor_prop/avoid_dizziness", 100);
                set("armor_prop/reduce_damage", 60);
                set("armor_prop/avoid_defense", 20);
                set("armor_prop/avoid_parry", 20);
                set("armor_prop/avoid_dodge", 20);
                set("armor_prop/avoid_force", 20);
                set("armor_prop/avoid_attack", 20);
                set("armor_prop/double_damage", 150);
                set("armor_prop/avoid_weak", 60);
                //set("armor_prop/avoid_chaos", 40);
                //set("armor_prop/avoid_lethargy", 40);
                set("armor_prop/avoid_freeze", 40);
                set("armor_prop/max_qi", 20000000);
                set("armor_prop/max_jing", 20000000);

                                set("wear_msg", NOR "$N�����ͳ�һ��" YEL "�ƺ�" NOR "�������С�\n" NOR);
                                set("remove_msg", NOR "$N�����е�" YEL "�ƺ�" NOR "�Ż�����Һá�\n" NOR);
                                set("stable", 100);
              } 
              setup(); 
              chkd();
} 




