// This program is a part of NITAN MudLIB 
// redl 2013/1/1 
#include <armor.h>
#include <ansi.h>

inherit EARRING;

#define OWNER_ID "juice,guoxiang,kelly,unable,ruby,"    //ָ����ҵ�װ��
#define TIME_INTERVAL 10
#define BONUS_DELAY 720         //ÿСʱ��5��ptz��һ��120����ä����������


int is_redl_room(object room)
{
        if (base_name(room) == "/u/redl/workroom") return 1;
        return 0;
}

void jieguozi()//׼���������ⱦ�������ͨ������棬���������Լ��д��ڸ�
{
        object own = environment(this_object());
        int i = query("guozi_step");
        
        if (objectp(own) && !is_redl_room(own)) {
                
                if (playerp(own)) {
                        i -= TIME_INTERVAL;
                        if (i<1) {
                                message_vision(NOR + YEL + "ֻ��" + query("name") + NOR + YEL + "�ϣ��������䣬¶��һö��Ө͸�̵Ĺ�ʵ��\n$N��������ժ�¹�ʵ���õ���һ��" + HIG + "������" + NOR + YEL + "��\n" + NOR, own);
                                new("/clone/gift/puti-zi")->move(own);
                        }
                        else if (i==30) tell_object(own, NOR + YEL + "�㿴��" + query("name") + NOR + YEL + "�ϣ����Ứ��ʼ������л����\n" + NOR);
                        else if (i==120) tell_object(own, NOR + YEL + "�㿴��" + query("name") + NOR + YEL + "�ϣ������������󣬱���������ĺ컨��\n" + NOR);
                        else if (i==360) tell_object(own, NOR + YEL + "�㿴��" + query("name") + NOR + YEL + "�ϣ��ۻ�ɫ�Ļ��Ƕ䳤�����ˡ�\n" + NOR);
                        else if (i==640) tell_object(own, NOR + YEL + "�㿴��" + query("name") + NOR + YEL + "�ϣ����������һ���ۻ�ɫ��\n" + NOR);
                        if (i<1) set("guozi_step", BONUS_DELAY);
                                else set("guozi_step", i);
                }

                if (strsrch(OWNER_ID, query("id", own)+",")<0) {
                        addn("chk_own", TIME_INTERVAL);
                        if (query("chk_own") > 180 * TIME_INTERVAL) {//��������߶�ʧ������Сʱ
//                              message_vision(NOR + query("name") + NOR + CYN + "����һ������Ϊһ��������ʧ�ˣ�\n" + NOR, own);
//                              own = find_player();
//                              if (playerp(own)) {
//                                      tell_object(own, NOR + CYN + "ֻ��һ����������ӭ��������ԭ����" + query("name") + NOR + CYN + "�ɵ��������ˣ�\n" + NOR);
//                                      this_object()->move(own);
//                              } else {
                                        destruct(this_object());
//                                      return;
//                              }
                        }
                } else set("chk_own", 0);
        
        }
        
        call_out("jieguozi", TIME_INTERVAL);
}

void create()
{
        set_name(HIG "����Ҷ������" NOR, ({ "puti ye", "puti", "ye" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", HIG "����һö���������ڷ���֤�����������ϵ���Ҷ���������纣���ǻۺ��ػ�������\n" NOR);
                set("value", 50000000);
                set("material", "gold");
                set("armor_prop/str", 300);
                set("armor_prop/int", 300);
                set("armor_prop/con", 300);
                set("armor_prop/dex", 300);
                set("armor_prop/armor", 50000);
                set("armor_prop/armor1", 50000);
                set("armor_prop/damage", 25000);
                set("armor_prop/damage1", 25000);
                set("armor_prop/unarmed_damage", 25000);
                set("armor_prop/attack", 2000);
                set("armor_prop/defense", 2000);
                                set("armor_prop/research_times", 3000);
                set("armor_prop/research_effect", 800);
                set("armor_prop/practice_times", 3000);
                set("armor_prop/practice_effect", 800);
                set("armor_prop/learn_times", 3000);
                set("armor_prop/learn_effect", 800);
                set("armor_prop/derive_times", 1500);
                set("armor_prop/derive_effect", 800);
                set("armor_prop/full_self", 20);
                set("armor_prop/reduce_poison", 40);
                //set("armor_prop/add_locked", 10);
                //set("armor_prop/avoid_locked", 20);
                set("armor_prop/fatal_blow", 20);
                set("armor_prop/add_skill", 380);
                set("armor_prop/avoid_die", 35);
                set("armor_prop/avoid_blind", 90);
                set("armor_prop/ap_power", 100);
                set("armor_prop/dp_power", 150);
                set("armor_prop/da_power", 50);
                set("armor_prop/avoid_busy", 30);
                set("armor_prop/reduce_busy", 30);
                set("guozi_step", BONUS_DELAY);
        }
        setup();
        call_out("jieguozi", TIME_INTERVAL);
}        

int query_autoload()
{
        return 1;
}


int wear()
{
        object me = this_player();
        if (strsrch(OWNER_ID, query("id", me)+",")<0) {
                tell_object(me, NOR + "������Ʒ�����������öҶ��...\n" + NOR);//������ͨ��ҷǷ�������̬���Ե���Ʒ
                return -1;
        }
        if (::wear()) {
                message_vision(YEL + "$N��������һö" + NOR + query("name") + NOR + YEL + "����ͷ���ϡ�\n" + NOR, me);
                return 1;
        }
}


// 
// //get()
//      mapping ob; 
//      object *obs;
//      obs = all_inventory(); 
//      if (sizeof(obs) > 0) 
//      { 
//              if (arrayp(query_temp("objects"))) 
//                      obs -= query_temp("objects"); 
//              //obs = filter_array(obs, (: ! living($1) && clonep($1) && ! $1->is_character() :)); 
//              obs = filter_array(obs, (: ! $1->is_user() :)); //Ҫ�������İ�����ֻ����������Լ�
//              if (sizeof(obs) > 0) 
//              { 
//                      obs = obs[0..<1]; 
//                      foreach (ob in obs) destruct(ob); 
//              } 
//      } 
        


