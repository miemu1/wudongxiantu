// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>
inherit ITEM;

#define EXPG 200000000

void create()
{
        set_name(NOR HIR"����"HIY"���"NOR,({"box"}));
        set("long", HIY "����һֻ��������Ʒ���ӣ���ͬ�ȼ�����ҿ��Ի�ò�ͬ����Ʒ��������������ţ�open box��������\n" NOR HIK "(���ߺ��ӵ��ᶪʧ���������ˣ��Ͽ�ʹ��)\n" NOR); 
        set("unit", "Щ");
        set("base_unit", "��");
                //set("no_give","�������������뿪�㡣\n");
                set("no_sell", "�������������뿪�㡣\n");
                set("no_put", "�����������ܷ����Ƕ���\n");
                set("no_store", "�����������ܷ����Ƕ���\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_steal", "�������������뿪�Ƕ���\n");
                set("no_beg", "�������������뿪�Ƕ���\n");
                set("base_value", 0);
                set("base_weight",1);
}

int give_ob(object me, object ob)
{
        ob->move(me, 1);
        tell_object(me, NOR + query("name") + NOR + "��ը��������" + query("name", ob) + NOR + "��\n");
        return 1;
}
int drop_ob(object me, object ob)//����Ҫ�ģ����ܳ��صĶ����ӵ���
{
        ob->move(environment(me));
        tell_object(me, NOR + query("name") + NOR + "��ը���㿴������ð����" + query("name", ob) + NOR + "��\n");
        return 1;
}

int do_open(string arg)
{
        object ob, me = this_player();
        int lv = query("level", me);
        string file = "/temp/qroom/" + query("id", me) + ".c";
        
        if (!arg || arg!="box") return 0;
        if( me->is_busy() ||
                me->is_fighting()
                ) {
                write(NOR BUSY_MESSAGE NOR);
                return 1;
        }
        if( query("doing", me) ) {
                write(NOR "����������æ�ڶ��������ܿ���С�\n" NOR);
                return 1; 
        }
        if( !query("no_fight", environment(me)) ) {
                write(NOR "������ڰ�ȫ�ĵط����ܿ���С�\n" NOR);
                return 1; 
        }
        if(sizeof(filter_array(all_inventory(environment(me)), (: playerp :))) < 5) {
                write(NOR "����뵽�˶����ֵĵط�(����������)ȥ����С�\n" NOR);//��ҫ+�ල
                return 1; 
        }
        
        me->start_busy(3);
        message_vision(NOR + CYN + "$N" + NOR + CYN + "̧�ִ�һ��" + query("name") + NOR + 
                CYN + "�����г����ɫϼ��һ��$N" + NOR + CYN + "��ʧ�ˡ�\n" + NOR, me);

        if (!sizeof(get_dir("/temp/qroom"))) mkdir("/temp/qroom"); 
        if (!(load_object(file)))  
                cp("/u/redl/teleport/qroom.c", file); 
        me->move(file); //�Ƶ����Կռ䣬���ⶫ�������ϱ���ȡ
        
        if (lv >= 160) {
                GIFT_D->work_bonus(me, ([ "prompt":"������ϼ���ˢϴ��֮��", "exp" : EXPG / 9, "pot" : EXPG / 36 ]));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/wangzhe-zhixin"));
                give_ob(me, new("/clone/goods/wangzhe-zhixin"));
                give_ob(me, new("/clone/goods/wangzhe-zhixin"));
                give_ob(me, new("/d/dongtian/emei/lingpai3"));
                give_ob(me, new("/d/dongtian/guanwai/lingpai3"));
                give_ob(me, new("/d/dongtian/huanghe/lingpai3"));
                give_ob(me, new("/d/dongtian/huangshan/lingpai3"));
                give_ob(me, new("/d/dongtian/songshan/lingpai3"));
                give_ob(me, new("/d/dongtian/yueyang/lingpai3"));
        }
        else if (lv >= 80) {
                GIFT_D->work_bonus(me, ([ "prompt":"������ϼ���ˢϴ��֮��", "exp" : EXPG / 3, "pot" : EXPG / 12 ]));
                ob = new("/clone/medicine/yuqingwan");
                ob->set_amount(3);
                give_ob(me, ob);
                ob = new("/clone/money/thousand-gold");
                ob->set_amount(50);
                drop_ob(me, ob);
                give_ob(me, new("/clone/goods/qianghua_crystal"));
                give_ob(me, new("/clone/goods/qianghua_crystal"));
                give_ob(me, new("/clone/goods/qianghua_crystal"));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/hongmeng-lingqi"));
                give_ob(me, new("/clone/goods/wangzhe-zhixin"));
                give_ob(me, new("/clone/goods/noname"));
                give_ob(me, new("/d/dongtian/emei/lingpai3"));
                give_ob(me, new("/d/dongtian/guanwai/lingpai3"));
                give_ob(me, new("/d/dongtian/huanghe/lingpai3"));
                give_ob(me, new("/d/dongtian/huangshan/lingpai3"));
                give_ob(me, new("/d/dongtian/songshan/lingpai3"));
                give_ob(me, new("/d/dongtian/yueyang/lingpai3"));
                give_ob(me, new("/d/dongtian/emei/lingpai3"));
                give_ob(me, new("/d/dongtian/guanwai/lingpai3"));
                give_ob(me, new("/d/dongtian/huanghe/lingpai3"));
                give_ob(me, new("/d/dongtian/huangshan/lingpai3"));
                give_ob(me, new("/d/dongtian/songshan/lingpai3"));
                give_ob(me, new("/d/dongtian/yueyang/lingpai3"));
        }
        else {
                GIFT_D->work_bonus(me, ([ "prompt":"������ϼ���ˢϴ��֮��", "exp" : EXPG, "pot" : EXPG / 4 ]));
                ob = new("/clone/medicine/yuqingwan");
                ob->set_amount(12);
                give_ob(me, ob);
                ob = new("/clone/gift/xuanhuang");
                ob->set_amount(200);
                drop_ob(me, ob);
                ob = new("/clone/money/thousand-gold");
                ob->set_amount(200);
                drop_ob(me, ob);
                give_ob(me, new("/clone/goods/noname"));
                give_ob(me, new("/clone/medal/yongshi_xunzhang"));
                give_ob(me, new("/clone/medal/vip_xunzhang"));
                give_ob(me, new("/clone/medal/diamond_xunzhang"));
                give_ob(me, new("/u/redl/obj/fanghuamu"));
                give_ob(me, new("/d/dongtian/obj/liudibi"));
                give_ob(me, new("/u/redl/obj/chutou3"));
                give_ob(me, new("/u/redl/obj/chutou3"));
                give_ob(me, new("/clone/goods/tianshi-charm"));
                give_ob(me, new("/clone/goods/tianshi-charm"));
        }
        give_ob(me, new("/u/redl/npc/obj/ntb2"));
        ob = new("/clone/gift/jiuzhuan");
        ob->set_amount(100);
        drop_ob(me, ob);
        destruct(this_object());
        return 1;
}

void init()
{
        add_action("do_open","open"); 
}

