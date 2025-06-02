// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>

#define CL_OBJ ({"/d/dongtian/emei/lingpai2", "/d/dongtian/songshan/lingpai2", "/d/dongtian/huangshan/lingpai2", "/d/dongtian/emei/lingpai", "/d/dongtian/songshan/lingpai", "/d/dongtian/huangshan/lingpai"})
#define CL_NUM 50

inherit NPC;

int drop_reward()
{
        object *inv, ob, me = this_player();

        if(me->is_busy()) {
                        write(NOR "����æ���ء�\n" NOR);
                        return 1;
        }
        
        me->start_busy(2);
        
        inv = filter_array(all_inventory(me),
                           (: 
                           query("dt_value", $1)
                           :));
                           
        if (arrayp(inv) && sizeof(inv)) foreach (ob in inv) {
                tell_object(me,CYN + query("name") + "��������������һ�鶴���\n"+ NOR); 
                destruct(ob);
        }
        
        return 1;
}

int get_reward()
{
                int amount;
        object me, obj, *inv;
        me = this_player();
        
        if(me->is_busy()) {
                        write(NOR "����æ���ء�\n" NOR);
                        return 1;
        }
        
        me->start_busy(2);

                inv = filter_array(all_inventory(me),
                           (: 
                           !$1->query_amount()
                           :));
                           
       if (arrayp(inv) && sizeof(inv) > 50) {
                tell_object(me,CYN + query("name") + "˵���������ϵĶ���̫���ˡ�\n"+ NOR); 
                return 1;
       }


        if( query("online_time", me) < 86400 * 14){
                tell_object(me,CYN + query("name") + "˵����������ʱ��û�г������ܣ���С�Űɣ�\n"+ NOR); 
                return 1;
        }      
        amount = query("combat_exp", me);
        if( amount < 1000000000){
                tell_object(me,CYN + query("name") + "˵������������Ϊ��ȥ�ܸ�ʲô��\n"+ NOR); 
                return 1;
        }
        if( query("dongtian/lingpai/test_gifttime", me) > time()  && wiz_level(me) < 6 ){
                tell_object(me,CYN + query("name") + "˵����������ÿ��ֻ����ȡһ�Σ�\n"+ NOR); 
                return 1;
        }
        
        amount = CL_NUM;
        while (amount--) {
                        obj = new(CL_OBJ[random(sizeof(CL_OBJ))]);
                        if ( wiz_level(me) < 6 ) {
                set("no_uget", "���ǲ�����Ʒ��", obj);
                set("no_drop", "���ǲ�����Ʒ��", obj);
                set("no_give", "���ǲ�����Ʒ��", obj);
                set("no_sell", "���ǲ�����Ʒ��", obj);
                set("no_get", "���ǲ�����Ʒ��", obj);
                set("no_steal", "���ǲ�����Ʒ��", obj);
                set("no_beg", "���ǲ�����Ʒ��", obj);
                set("no_put", "���ǲ�����Ʒ��", obj);
                set("no_store", "���ǲ�����Ʒ��", obj);
            }
                        obj->move(me);
        }
        set("dongtian/lingpai/test_gifttime", time() + 86400, me);
        message_vision(YEL + query("name") + NOR + YEL+ "�ó�"+chinese_number(CL_NUM)+"�鶴�����"+ NOR +"$N"+ NOR + YEL+"��\n" + NOR, me);        
        return 1;
}      

int go_dt(string arg)
{
        object me = this_player();
        
        if (arg=="emei") me->move("/d/dongtian/emei/enter");
        if (arg=="songshan") me->move("/d/dongtian/songshan/enter");
        if (arg=="huangshan") me->move("/d/dongtian/huangshan/enter");
        return 1;
}

void create()
{
        set_name(NOR MAG "����ʹ��" NOR, ({ "t", "ceshi shizhe", "tester" }));
        set("long", @LONG
���ڷ�����<ask t about all>��
LONG);
        set("gender", "����" );
        set("age", 30);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 1200000);

        set("inquiry", ([
                "������" : (: get_reward :),
                "���ٶ�����" : (: drop_reward :),
                "emei" : (: go_dt("emei") :),
                "songshan" : (: go_dt("songshan") :),
                "huangshan" : (: go_dt("huangshan") :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}



