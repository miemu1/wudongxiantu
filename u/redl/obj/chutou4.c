// This program is a part of NITAN MudLIB 
// redl 2013/4/1 
#include <ansi.h>

inherit ITEM;

int halt_diging(object me)
{
        message_vision(YEL + "$N����"+query("name")+ NOR + YEL + "���˲�����\n" + NOR,  me);
        delete_temp("toucai", me);
        me->set_short_desc(0);
        me->stop_busy();
        me->start_busy(2);
        return 1;
}

int diging(object me)
{
        int stage, rnd, exp, i;
        object tool = query_temp("toucai_tool", me);

        if (!objectp(tool) || environment(tool) != me)
        {
                        tell_object(me, "��...��ĳ�ͷ�أ�\n");
                delete_temp("toucai", me);
                me->set_short_desc(0);
            me->stop_busy();
            me->start_busy(6);
                return 1;
        }        

        if (query("nj", tool) < 1 ){
                        message_vision(NOR + "$N�����"+query("name")+ NOR + "����һ��ɢ���ˡ�\n" + NOR,  me);
                me->set_short_desc(0);
            me->stop_busy();
                me->start_busy(2);
                        destruct(this_object());
                return 1;
        }
        
        switch(stage=query_temp("toucai", me) )
        {
        case 1:
        case 2:
        case 3:
        case 4:
                if (random(10))//��Ϊ���ڱ�ʯ���ز���̫�죬�����ٶȣ�
                {
                        tell_object(me, "��������ٷ��Ų˵ء�\n");
                        break;
                }

                tell_object(me, "���ھ����𽥷�����..\n");
                stage++;
                break;
        case 5:
                        tell_object(me, "�����ͷʱ�ƺ���Щ����...\n");
                stage++;
                break;
        case 6:
                        rnd = random(1000);
                        exp = 280 + random(100);
                if (rnd<6){//³�������
                        tell_object(me, CYN + "����ǰͻȻ����һ���ִ���б��ȵ�������������Ƥ���������ҵ���͵�ˣ�\n" + 
                                                                  "˵��һ���ײ���С��ȭͷ������������æ�ؾ���С��ͷһ��ܣ������ꡱһ��\n" +
                                                                  "��ĳ�ͷ����ˣ�����Ҳ��������...\n" + NOR);
                        addn("nj", -100, tool);
                                        set_temp("block_msg/all",1 ,me);
                        message_vision(YEL + "һ����Ӱ�����Ƶ�һ����ȣ�$N��û���ü���Ӧ�����Ͼ����ذ���һȭ��\n" + NOR, me);
                        delete_temp("block_msg/all", me);
                        //me->unconcious();//����͵���Ļ���

                                delete_temp("toucai", me);
                                me->set_short_desc(0);
                                me->stop_busy();
                                me->start_busy(2);
                                return 1;
                }
                else if (rnd<33){//����ʯ=�����ƽ�
                        for(i = random(3) + 2; i > 0; i--) {
                                message_vision(YEL + "$Nһ��ͷ��ȥ����ડ�һ�����ƺ��ڵ���ʲô��\n$N��ϲ֮���ٳ�һ���������Ӳ�ﴧ�����\n" + NOR, me);
                                new("/clone/money/yuanbao")->move(me);
                        }
                                if (query("combat_exp", me)>1000000) GIFT_D->work_bonus(me, ([ "exp" : exp, "pot" : exp / 4 ]));
                }
                else if (rnd<334){
                                        for(i = random(3) + 2; i > 0; i--) {
                                message_vision(YEL + "$Nһ��ͷ��ȥ����ડ�һ�����ƺ��ڵ���ʲô��\n$N��ϲ֮���ٳ�һ�鲻֪���ı�ʯ�������\n" + NOR, me);
                                rnd = random(5);
                                switch(rnd)
                                {
                                        case 0:
                                                new("/clone/tessera/cdiamond")->move(me);
                                                break;
                                        case 1:
                                                new("/clone/tessera/cemerald")->move(me);
                                                break;
                                        case 2:
                                                new("/clone/tessera/csapphire")->move(me);
                                                break;
                                        case 3:
                                                new("/clone/tessera/cruby")->move(me);
                                                break;
                                        default:
                                                new("/clone/tessera/ctopaz")->move(me);
                                                break;
                                }
                        }
                        exp /= 3;
                        if (query("combat_exp", me)>1000000) GIFT_D->work_bonus(me, ([ "exp" : exp, "pot" : exp / 4 ]));
                }
                else {
                        message_vision(YEL + "$Nһ��ͷ��ȥ�����ꡱһ�����ڵ�һ��ճ����ðײˣ�\n$N�㬵ذ��ðײ��ӵ�һ�ߣ���߶���������յ��磬͵�����ҿࡱ��\n" + NOR, me);
                        exp /= 6;
                        if (query("combat_exp", me)>1000000) GIFT_D->work_bonus(me, ([ "exp" : exp, "pot" : exp / 4 ]));
                }

                //stage = 1;
                //me->set_short_desc(0);
                //break;
                
                                halt_diging(me);
                                return 1;
                default:
                    me->set_short_desc(0);
                    me->stop_busy();
                        me->start_busy(2);
                                return 1;
        }
        
        set_temp("toucai", stage, me);
        return 1;
}

int move(mixed dest, int raw)
{
        object me;

        if (me = query_temp("owner"))
                me->interrupt_me();

        return ::move(dest, raw);
}


int do_dig()//string arg)
{
        object *obs;
        object where;
        object me = this_player();
        
//              if (! arg || arg != "cai"){
//                      tell_object(me, "��Ҫ��ʲô��\n");
//                      return 1;
//              }
               
        if (me->is_busy() || me->is_fighting()){
                        tell_object(me, "�㻹��æ����ͷ�ϵ�������˵�ɡ�\n");
                        return 1;
                }
  if ( !interactive(this_player()) ) return 1;
                
//         if (query("combat_exp", me)>5000000){
//              tell_object(me, "��ʵս��Ϊ����������ˣ����������ֶ��������ˡ�\n");
//                      return 1;
//              }
// 
//         if (query("combat_exp", me)<1000000){
//              tell_object(me, "��ʵս��Ϊ������һ���򣬷������뷨�ɡ�\n");
//                      return 1;
//              }

                where = environment(me);
/*
                if (!sscanf(base_name(where), "/d/kaifeng/caidi%*s")){
                        tell_object(me, "���ﲻ�ǿ��������µĲ˵ذɣ�\n");
                        return 1;
                }
*/
                if (strsrch(query("short", where), "�˵�") == -1) {
                        tell_object(me, "���ﲻ�ǲ˵ذɣ�\n");
                        return 1;
                }

        obs = filter_array(all_inventory(where),
                           (: interactive($1) &&
                             $1 != $(me) &&
                             query_temp("toucai", $1) :));

        if (sizeof(obs) > 10)
        {
                 tell_object(me, "�����Ѿ���" + sizeof(obs) + "������͵���ˣ���ȵȰɡ�\n");
                 return 1;
        }

                
                if (query("nj") < 1) {
                        message_vision(NOR + "$N�����"+query("name")+ NOR + "����һ��ɢ���ˡ�\n" + NOR,  me);
                        destruct(this_object());
                        return 1;
                } else addn("nj", -1);

        message_vision(YEL + "$N������������һ��С�����˿���Χ�����ٵض�����������..\n" + NOR, me);
        set_temp("toucai", 1, me);
        set_temp("toucai_tool", this_object(), me);
        me->start_busy((: call_other, __FILE__, "diging" :),
                       (: call_other, __FILE__, "halt_diging" :));
                me->set_short_desc("����͵�ˡ�");
        return 1;
}



void init()
{
        if (interactive(this_player()) &&
            environment() == this_player())
        {
                add_action("do_dig", "toucai");
                add_action("do_dig", "wacai");
        }
}

void create()
{
        set_name(HIY "���" BLINK HIR "��" HIC "��" NOR HIW "��" NOR, ({ "jingang chu", "chu tou", "chu" }));
        /*if (clonep())
                set_default_object(__FILE__);
        else
        {*/
                set("unit", "��");
                set("long", "����һ�����ڲ˵���ʹ�õ�С��ͷ��\n����д�š�����������.�ơ���ָ��(toucai)����(wacai)��\n");//����emote wa�ظ�cmd dig�ظ�
                set("value", 1);
                set("weight", 50000000);
                set("nj", 3000);
                set("no_store", "�����������ܷ����Ƕ���\n");
                set("no_steal", "�������������뿪�Ƕ���\n");
                set("no_beg", "�������������뿪�Ƕ���\n");
                                set("set_data", 1); 
                                set("auto_load", 1); 
        //}

        setup();
}

