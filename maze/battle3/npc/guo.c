// guojing.c ����

#define RIDE_CMD        "/cmds/std/ride"  
inherit NPC;
#include <ansi.h>

int give_quest(string arg); 
void create()
{
        set_name("����", ({"guo jing", "guo", "jing"}));
        set("nickname", HIY "����" NOR);
        set_temp("title", HIW"���α����Ԫ˧"NOR);
        set("gender", "����");
        set("age", 41);
        set("long",
                "�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������\n"
                "�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ����\n"
                "��ͨ���˵�ͽ�ܣ���������书��������һ����ɫ���ۣ���̬\n"
                "���࣬�غ����Ŀ��͸��һ�����ϡ�\n");
        set("attitude", "friendly");
        set_max_encumbrance(100000000);
        set_temp("warquest/party", "song");
        set("per", 20);
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����̾�˿����������ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ�����ߣ���....\n",
                "����˵���������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ��������\n",
        }));

        set("inquiry", ([
                "�ܲ�ͨ" : "��������ܴ���ˣ������ڿɺã�\n",
                "����ͯ" : "�ܴ��һ��������û��������\n",
                "���߹�" : "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�\n",
                "��ҩʦ" : "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�\n",
                "һ�ƴ�ʦ" : "���¶Դ�ʦ�����м���\n",
                "ŷ����" : "����϶����������λʦ����һ���������ˣ������������ݡ�\n",
                "����"   : "�ض����ҵİ��ޣ�������������\n",
                "�ض�"   : "�ض������ض��ˡ�������ô����\n",
                "��ܽ"   : "���Ů�����ֱ��ֲ�������\n",
                "����"   : "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����\n",
                "����²" : "�����ҵ�С���ӡ�\n",
                "���"   : "����ȷʵ�г�Ϣ��\n",
                "����"   : "����������а�ʦ֮�ꡣ\n",
                "�𴦻�" : "������屡���죬������ܡ�\n",
                "�����" : "�����Ҵ�ʦ����\n",
                "���"   : "�����Ҷ�ʦ����\n",
                "������" : "��������ʦ����\n",
                "��ϣ��" : "��������ʦ����\n",
                "�Ű���" : "��������ʦ����\n",
                "ȫ��" : "��������ʦ����\n",
                "��СӨ" : "��������ʦ����\n",
                "ؤ��"   : "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�\n",
                "��ʦ"   : "�����ɹ���Χ��������������������ͽ����\n",
                "��ȡ����" : "��ʽ��lingming houqin-baozhang",
                ]));

        set("qi", 10000);
        set("max_qi", 10000);
        set("jing", 8000);
        set("max_jing", 8000);
        set("neili", 34000);
        set("max_neili", 34000);
        set("jiali", 500);

        set("combat_exp", 25000000);
        set("score", 200000);

        set_skill("force", 400);                // �����ڹ�
        set_skill("huntian-qigong", 400);       // ��������
        set_skill("strike", 400);               // ����ȭ��
        set_skill("dragon-strike", 400);        // ����ʮ����
        set_skill("dodge", 400);                // ��������
        set_skill("xiaoyaoyou", 400);           // ��ң��
        set_skill("parry", 400);                // �����м�
        set_skill("arrow", 400);
        set_skill("lianzhu-arrow", 400);

        map_skill("arrow", "lianzhu-arrow");
        map_skill("force", "huntian-qigong");
        map_skill("strike", "dragon-strike");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dragon-strike");
        prepare_skill("strike", "dragon-strike");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.xian" :),
                (: perform_action, "strike.hui" :),
                (: perform_action, "strike.lei" :),
                (: perform_action, "strike.leiting" :),
                (: perform_action, "strike.pai" :),
                (: perform_action, "strike.qin" :),
                (: perform_action, "strike.sanhui" :),
                (: perform_action, "strike.xianglong" :),
                (: exert_function, "recover" :),
                (: exert_function, "regenerate" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shengang" :),
                (: exert_function, "shexin" :),
        }) );

        setup();

        carry_object("/clone/misc/cloth")->wear();
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

