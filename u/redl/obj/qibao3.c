// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <armor.h>
#include <ansi.h>

inherit EARRING;

#define TIME_INTERVAL 10        //BONUS_DELAY��������������������Ҵ���640
#define BONUS_DELAY 2160        //һ��40��
#define BONUS_EXP 750000        //ÿ�ν���exp


void jieguozi()
{
        object own = environment(this_object());

        int i = query("guozi_step");
                if ( objectp(own) && playerp(own) && (query("id", own) == query("me_id")) && query("equipped") == "worn" ) {
                        i -= TIME_INTERVAL;
                        if (i<1) {
                                //tell_object(own, NOR + YEL + "ֻ��" + HIG + "�߱�����������" + NOR + YEL + "�ϣ��������䣬¶����ö��Ө͸�̵Ĺ�ʵ��\n$N��������ժ�¹�ʵ���õ��������䱦��\n" + NOR);
                                if (!random(3)) new("/clone/tessera/diamond")->move(own);
                                if (!random(3)) new("/clone/tessera/emerald")->move(own);
                                if (!random(3)) new("/clone/tessera/sapphire")->move(own);
                                if (!random(3)) new("/clone/tessera/ruby")->move(own);
                                if (!random(3)) new("/clone/tessera/topaz")->move(own);
                for(int i2 = 10; i2 > 0; i2--) {
                        new("/clone/gift/xuanhuang")->move(own);
                }
                                new("/clone/medicine/yuqingwan")->move(own);
                        addn("combat_exp", BONUS_EXP, own);
                                addn("yuanshen_exp", BONUS_EXP / 4, own);
                        addn("potential", BONUS_EXP / 4, own);
                        addn("experience", BONUS_EXP / 8, own);
//                              call_other(GIFT_D, "bonus", own, ([ "exp":BONUS_EXP, "pot":BONUS_EXP/4, "mar":BONUS_EXP/8, "prompt":"�����߱������²����˴������֮��"]));
                        }
//                      else if (i==30) tell_object(own, NOR + YEL + "�㿴��" + HIG + "�߱�����������" + NOR + YEL + "�ϣ����Ứ��ʼ������л����\n" + NOR);
//                      else if (i==120) tell_object(own, NOR + YEL + "�㿴��" + HIG + "�߱�����������" + NOR + YEL + "�ϣ������������󣬱���������ĺ�������\n" + NOR);
//                      else if (i==360) tell_object(own, NOR + YEL + "�㿴��" + HIG + "�߱�����������" + NOR + YEL + "�ϣ��ۻ�ɫ�Ļ��Ƕ䳤�����ˡ�\n" + NOR);
//                      else if (i==640) tell_object(own, NOR + YEL + "�㿴��" + HIG + "�߱�����������" + NOR + YEL + "�ϣ����������һ���ۻ�ɫ��\n" + NOR);
                        if (i<1) set("guozi_step", BONUS_DELAY);
                                else set("guozi_step", i);
                }

        call_out("jieguozi", TIME_INTERVAL);

        if (  objectp(own) && query("me_id") ) 
                if (query("id", own) != query("me_id")) destruct(this_object());//����������ʱ
                else if (!query("env/invisible_item", own)) destruct(this_object());//����û����������ʱ
}

void create()
{
        set_name(HIR "�Ͻ𻨶���" NOR, ({ "zijinhua erhuan3", "qibao miaoshu", "qibao", "erhuan" }));
        set_weight(100);
                set("unit", "ö");
//                 set("long", HIG "�߱�����������������������֤����������֦���ƣ��������纣���ǻۡ�\n" NOR);
                 set("long", HIR "����һö������\n" NOR);
                set("value", 500000000);
                set("material", "gold");
                set("armor_prop/str", 100);
                set("armor_prop/int", 200);
                set("armor_prop/con", 100);
                set("armor_prop/dex", 100);
                set("armor_prop/armor", 10000);
                //set("armor_prop/armor1", 10000);
                set("armor_prop/damage", 5000);
                //set("armor_prop/damage1", 5000);
                set("armor_prop/unarmed_damage", 5000);
                set("armor_prop/attack", 1000);
                set("armor_prop/defense", 1000);
                                set("armor_prop/research_times", 300);
                set("armor_prop/research_effect", 300);
                set("armor_prop/practice_times", 300);
                set("armor_prop/practice_effect", 300);
                set("armor_prop/learn_times", 300);
                set("armor_prop/learn_effect", 300);
                set("armor_prop/derive_times", 300);
                set("armor_prop/derive_effect", 300);
                set("armor_prop/full_self", 20);
                set("armor_prop/reduce_poison", 30);
                //set("armor_prop/add_locked", 10);
                //set("armor_prop/avoid_locked", 20);
                set("armor_prop/fatal_blow", 10);
                set("armor_prop/add_skill", 180);
                set("armor_prop/avoid_die", 25);
                set("armor_prop/avoid_blind", 90);
                set("armor_prop/ap_power", 50);
                set("armor_prop/dp_power", 60);
                set("armor_prop/da_power", 40);
                set("armor_prop/avoid_busy", 25);
                set("armor_prop/reduce_busy", 20);
                set("armor_prop/max_qi", 300000); 
                set("armor_prop/max_jing", 200000); 
                set("armor_prop/max_neili", 800000); 
                set("armor_prop/max_jingli", 600000); 
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                set("guozi_step", BONUS_DELAY);
        setup();
        call_out("jieguozi", TIME_INTERVAL);
}        

int wear()
{
        object me = this_player();
        if (query("id", me) != query("me_id")) {
                tell_object(me, NOR + "�㲻���������������Ʒ��\n" + NOR);//������ͨ��ҷǷ�������̬���Ե���Ʒ
                return -1;
        }
        if (::wear()) {
                //message_vision(YEL + "$N��������һö" + NOR + query("name") + NOR + YEL + "���ڶ����ϡ�\n" + NOR, me);
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
        set("env/invisible_item", 1, me);
        this_object()->move(me);
        tell_object(me, "����������װ���߱�������look erhuan\n��Ҫ��������չʾ�����ˣ�����������ʧ��\n");
        write("�߱���������Ϊ" + arg + "ר�õģ�\n");
        return 1;
}

void init()
{
        add_action("do_name", "name");
}


        
