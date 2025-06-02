#include <ansi.h>
#define RIDE_CMD        "/cmds/std/ride" 
inherit NPC;

int give_quest(string arg);

void create()
{
        set_name("���μ��", ({"jian jun", "jian", "jun"}));
        set("title", HIR "����̫��" NOR);
        set("gender", "����");
        set("age", random(20) + 20);

        set("long", "����һ�����ǻʹ��е�һ��̫�࣬���𿹻��ɹž������ִ��εļ����\n");
        set("combat_exp", 800000);
        set("attitude", "peaceful");
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("max_neili", 2000);
        set("neili", 1000);
        set("no_get", 1);
        set("inquiry", ([ 
                "��ȡ����" : "��ʽ��lingming yayun-liangcao",
        ]));

        setup();
        carry_object("clone/cloth/cloth")->wear();
}

void init()
{
        add_action("give_quest", ({ "lingming" }));
}


int give_quest(string arg)
{
        object me, ob, ling;
        object horse;
        int count;
        
        ob = this_player();
        me = this_object();
        
        if (! arg)
        {
                tell_object(ob, "����Ҫ����ȥ��ʲô���飿��\n");
                return 1;
        }
        
        if( query_temp("warquest/party", ob) != "song" )
        {
                tell_object(ob, "�㻹û�вμ��ξ����������������\n");
                return 1;
        }
                
        switch(arg)
        {
        case "train-infantry":
        case "xunlian-bubing":
                if( query_temp("warquest/train", ob )
                 && query_temp("warquest/train", ob) != "infantry" )
                {
                        tell_object(ob, "���Ѿ�������ְ�ˣ�\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������м�����ս֮ʦ��\n����ӽ�ѵ��һ֧���񲽱����Ա���ʱ֮�裬" +
                               "��������\n" NOR, me, ob);
                set_temp("title", HIW"���β���Ӫͳ��"NOR, ob);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        set("owner",query("id",  ob), ling);
                        ling->move(ob);
                }
                set_temp("warquest/train", "infantry", ob);
                set_temp("warquest/quest", "ѵ����������ս׼��", ob);
                ob->command("drill");
                break;

        case "xunlian-qibing":
        case "train-cavalry":
                if( query_temp("warquest/train", ob )
                 && query_temp("warquest/train", ob) != "cavalry" )
                {
                        tell_object(ob, "���Ѿ�������ְ�ˣ�\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������м�����ս֮ʦ��\n����ӽ�ѵ��һ֧����������Ա���ʱ֮�裬" +
                               "��������\n" NOR, me, ob);

                set_temp("title", HIR"���γ���Ӫͳ��"NOR, ob);
                if (! present("zhan ma", ob))
                {
                        horse = new("/maze/battle3/song/horse");
                        if (horse->move(environment(ob)))
                                RIDE_CMD->do_ride(ob, horse);
                        else destruct(horse);
                }
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        set("owner",query("id",  ob), ling);
                        ling->move(ob);
                }
                set_temp("warquest/train", "cavalry", ob);
                set_temp("warquest/quest", "ѵ���������ս׼��", ob);
                ob->command("drill");
                break;

        case "train-archer":
        case "xunlian-gongnu":
                if( query_temp("warquest/train", ob )
                 && query_temp("warquest/train", ob) != "archer" )
                {
                        tell_object(ob, "���Ѿ�������ְ�ˣ�\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������м�����ս֮ʦ��\n����ӽ�ѵ��һ֧���񹭼��֣��Ա���ʱ֮�裬" +
                               "��������\n" NOR, me, ob);
                set_temp("title", HIB"��������Ӫͳ��"NOR, ob);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        set("owner",query("id",  ob), ling);
                        ling->move(ob);
                }

                set_temp("warquest/train", "archer", ob);
                set_temp("warquest/quest", "ѵ����������ս׼��", ob);
                ob->command("drill");
                break;
                
        case "houqin-baozhang":
                count = 600000;
                if( WAR_D->query_moneys() < 600000 )
                {
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������������ѷ���\n��������ʲ����ڰ����ڽ���ʦ��Ӧ֮����Ѻ��" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);

                        set_temp("title", HIY"���ξ���Ӫͳ��"NOR, ob);
                        if (! present("ling jian", ob))
                        {
                                ling = new("/adm/npc/obj/lingjian");
                                set("owner",query("id",  ob), ling);
                                ling->move(ob);
                        }
                        set_temp("warquest/purchase", "forage", ob);
                        set_temp("warquest/quest", "Ѻ�����ݣ��������", ob);
                        ob->command("stock");
                } 
                else if( WAR_D->query_soilders(me) < 2000 )
                {        
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������б�Ա�ѷ���\n��������ʲ�����ȥ����������ļ�±�" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                        set_temp("title", HIY"���ξ���Ӫͳ��"NOR, ob);
                        if (! present("ling jian", ob))
                        {
                                ling = new("/adm/npc/obj/lingjian");
                                set("owner",query("id",  ob), ling);
                                ling->move(ob);
                        }
                        set_temp("warquest/purchase", "enlist", ob);
                        set_temp("warquest/quest", "��ļ�±��������Դ", ob);
                        WAR_D->change_moneys(-count);
                        ob->command("stock");
                }
                else if( WAR_D->query_weapons(me) < 4000 )
                {               
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������б����Ϳ����ѷ���\n��������ʲ�����ȥ�������ڲɹ������Ϳ���" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                        set_temp("title", HIY"���ξ���Ӫͳ��"NOR, ob);
                        if (! present("ling jian", ob))
                        {
                                ling = new("/adm/npc/obj/lingjian");
                                set("owner",query("id",  ob), ling);
                                ling->move(ob);
                        }
                        set_temp("warquest/purchase", "weapon", ob);
                        set_temp("warquest/quest", "���ñ��ף��������", ob);
                        WAR_D->change_moneys(-count);
                        ob->command("stock");
                }
                else if( WAR_D->query_arrows(me) < 2000 )
                {
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "������Ӫ��¥����ѷ���\n��������ʲ�����ȥ�������ڲɹ����" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                        set_temp("title", HIY"���ξ���Ӫͳ��"NOR, ob);
                        if (! present("ling jian", ob))
                        {
                                ling = new("/adm/npc/obj/lingjian");
                                set("owner",query("id",  ob), ling);
                                ling->move(ob);
                        }
                        set_temp("warquest/purchase", "arrow", ob);
                        set_temp("warquest/quest", "����������������", ob);
                        WAR_D->change_moneys(-count);
                        ob->command("stock");
                }
                else if( WAR_D->query_horses(me) < 2000 )
                {
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "��������ս���ѷ���\n��������ʲ�����ȥ�������ڲɹ�ս��" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                        set_temp("title", HIY"���ξ���Ӫͳ��"NOR, ob);
                        if (! present("ling jian", ob))
                        {
                                ling = new("/adm/npc/obj/lingjian");
                                set("owner",query("id",  ob), ling);
                                ling->move(ob);
                        }
                        set_temp("warquest/purchase", "horse", ob);
                        set_temp("warquest/quest", "����ս���������", ob);
                        WAR_D->change_moneys(-count);
                        ob->command("stock");
                }
                else if( WAR_D->query_stones(me) < 2000 )
                {
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������й�ʯ����ľ�ѷ���\n��������ʲ�����ȥ�������ڲɹ�ʯͷ��ľ��" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                        set_temp("title", HIY"���ξ���Ӫͳ��"NOR, ob);
                        if (! present("ling jian", ob))
                        {
                                ling = new("/adm/npc/obj/lingjian");
                                set("owner",query("id",  ob), ling);
                                ling->move(ob);
                        }
                        set_temp("warquest/purchase", "stone", ob);
                        set_temp("warquest/quest", "����ʯľ���������", ob);
                        WAR_D->change_moneys(-count);
                        ob->command("stock");
                }
                else if( WAR_D->query_economy(me) < 1200000 )
                {
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�����ɹ������ɧ���Ҵ��������ǣ�\n��������ʲ�����ȥ����פ�سǳ�" +
                               "���������󣬾����۴���\n" NOR, me, ob);
                        set_temp("title", HIY"���κ��Ӫͳ��"NOR, ob);

                        set_temp("warquest/guard", 1, ob);
                        set_temp("warquest/quest", "�����������ȹ̺�", ob);
                        // ob->command("guard");
                        ob->move("/d/xiangyang/guofuting");
                }
                else
                {
                        message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������������ѷ���\n��������ʲ����ڰ����ڽ���ʦ��Ӧ֮����Ѻ��" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);

                        set_temp("title", HIY"���ξ���Ӫͳ��"NOR, ob);
                        if (! present("ling jian", ob))
                        {
                                ling = new("/adm/npc/obj/lingjian");
                                set("owner",query("id",  ob), ling);
                                ling->move(ob);
                        }
                        set_temp("warquest/purchase", "forage", ob);
                        set_temp("warquest/quest", "Ѻ�����ݣ��������", ob);
                        ob->command("stock");
                }
                break;
        default:
                tell_object(ob, "����Ҫ������ʲô���飿��\n");
                return 1;
        }

        message_vision("�ڽ������Ӧ����ĩ����������\n", me, ob);
        return 1;
}

int accept_hit(object me)
{
        if (playerp(me))
        {
                command("heng");
                command("say ��Ҫ��Ҫ������");
                return 0;
        }
}

int accept_fight(object me)
{
        if (playerp(me))
        {
                command("heng");
                command("say ��Ҫ��Ҫ������");
                return 0;
        }
}

int accept_kill(object me)
{
        if (playerp(me))
        {
                message_vision(CYN "$N" CYN "��ŭ�����������������������������˵��һ�ư�$n" CYN
                               "�����ڵء�\n" NOR, this_object(), me);
                me->unconcious();
                return -1;
        }
}
