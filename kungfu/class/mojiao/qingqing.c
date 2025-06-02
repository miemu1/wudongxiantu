// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#define MOON_BLADE    "/clone/lonely/moonblade"

mixed ask_blade();

void create()
{
        set_name("����", ({"qing qing", "qing"}));
        set("gender", "Ů��");
        set("age", 21);
        set("shen_type", -1);
        set("long", "
����һ����ɫ���·��������Ǵ������ʵ���գ�
������峺�ĺ�ˮ����ˮ�е�ӳ�ŵ�Զɽ������
���ض����ʡ�Ц�����£����ᣬ���࣬�߹���
�Ϲ���һ���䵶���䵶���ô��������ʣ�������
����һ������Բ������顣");

        set("attitude", "peaceful");

        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 10000);
        set("max_jing", 10000);
        set("neili", 130000);
        set("max_neili", 130000);
        set("jiali", 3000);

        set("combat_exp", 150000000);
        set("score", 0);

        set_skill("force", 280);
        set_skill("moshen-xinfa", 280);
        set_skill("chiyou-kuangzhanjue", 250);
        set_skill("dodge", 280);
        set_skill("moshen-bufa", 280);
        set_skill("jiutian-xiaoyaobu", 250);
        set_skill("strike", 280);
        set_skill("moshen-zhangfa", 280);
        set_skill("cuff", 280);
        set_skill("moshen-quanfa", 280);
        set_skill("sword", 280);
        set_skill("moshen-jianfa", 280);
        set_skill("blade", 280);
        set_skill("moshen-daofa", 280);
        set_skill("moon-blade", 280);
        set_skill("parry", 250);
        set_skill("literate", 210);
        set_skill("medical", 200);
        set_skill("mojiao-medical", 200);

        map_skill("force", "chiyou-kuangzhanjue");
        map_skill("dodge", "jiutian-xiaoyaobu");
        map_skill("strike", "moshen-zhangfa");
        map_skill("cuff", "moshen-quanfa");
        map_skill("sword", "moshen-jianfa");
        map_skill("blade", "moon-blade");
        map_skill("parry", "moon-blade");

        prepare_skill("strike", "moshen-zhangfa");

        create_family("ħ��", 40, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.ting" :),
                (: perform_action, "blade.yue" :),
                (: exert_function, "recover" :),
        }) );

        set("inquiry", ([
                "Բ���䵶"      : (: ask_blade :),
                "Բ��ħ��"      : (: ask_blade :),
        ]));

        set_temp("apply/attack", 280);
        set_temp("apply/damage", 280);
        set_temp("apply/unarmed_damage", 280);
        set_temp("apply/armor", 280);

        set("master_ob", 5);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        add_money("silver",70);
}

void attempt_apprentice(object ob)
{
        command("say �Ҳ���ͽ���㻹���������˰ɣ�");
}
/*
int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "��ʱ������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/moon-blade/yue",
                           "name"    : "��ʱ������",
                           "sk1"     : "moon-blade",
                           "lv1"     : 300,
                           "dodge"   : 300,
                           "gongxian": 1000,
                           "shen"    : -50000, ]));
                break;

        case "С¥һҹ������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/moon-blade/ting",
                           "name"    : "С¥һҹ������",
                           "sk1"     : "moon-blade",
                           "lv1"     : 300,
                           "dodge"   : 300,
                           "gongxian": 1000,
                           "shen"    : -50000, ]));
                break;

        default:
                return 0;
        }
}
*/
int recognize_apprentice(object ob, string skill)
{
        object blade, owner;

        blade = find_object(MOON_BLADE);
        if (! blade) blade = load_object(MOON_BLADE);
        owner = environment(blade);

        if (owner != ob)
        {
                command("say �㻹�����õ�Բ���䵶����������ѧϰԲ�µ����ɣ�");
                return -1;
        }

        if (ob->query_skill(skill, 1) >= 180)
        {
                command("say ���ˣ��Ҿͽ��㵽����ɣ��书����"
                        "Ҫ���Լ����о����ǣ�");
                return -1;
        }

        if (ob->query_temp("can_learn/qingqing/moon-blade") &&
            skill == "blade")
                return 1;

        if (ob->query_temp("can_learn/qingqing/moon-blade") &&
            skill == "moon-blade")
                return 1;

        if (skill == "moon-blade")
        {
                if (ob->query("family/family_name") != "ħ��")
                {
                        command("say ���������ԨԴ����ΪʲôҪ�����书��");
                        return -1;
                }

                message_vision("$N���˿�$n�����ͷ����Բ�µ���Ҳû��ʲô��ѧ�ġ�\n",
                               this_object(), ob);
                ob->set_temp("can_learn/qingqing/moon-blade", 1);
                return 1;
        }

        command("say ��ֻ����һ��Բ�µ�������ɲ�ҪΪ���ҡ�");
        return -1;
}

mixed ask_blade()
{
        object ob,owner;
        object gift;
        object me;

        me = this_player();
        if (me->query("family/family_name") != query("family/family_name"))
                return "����������";

        if ((int)me->query("combat_exp")<2000000)
                return "���书̫���ˣ��ͱ����ħ�̶����ˡ�";
/*
        if (me->query("birthday") < 1234804783 && ! me->query("washgift", 1)) {
        gift = new("/clone/item/washgift");
        gift->move(me, 1);
        gift->set("bindable", 3);
        gift->set("bind_owner", me->query("id"));
        gift->set("autoload", 1);
        gift->set("setdbase", 1);
        me->set("washgift", 1);
        tell_object(me, HIW "���������һ��ϴ�츳����\n" NOR);
        }
*/
        call_other(MOON_BLADE, "???");
        ob = find_object(MOON_BLADE);
        if (! objectp(ob))
                return "��û�ˣ�";

        if (objectp(owner = environment(ob)))
        {
                if(owner == me)
                {
                        destruct(ob);
                        return "��ʲô��˼����Ҫ���û����\n";
                }
                if(owner->is_character())
                {
                        return "���Ѿ���" + owner->name(1) + "�����ˡ��ȹ黹��������ȡ�ɡ�\n";
                }
                return "���Ѿ����˽����ˡ����ڲ�֪����ʲô�ط���\n";
        }
        ob->move(me, 1);
        ob->start_borrowing();
        message_vision("$N�ͳ�һ������ѿ�������䵶���ݸ�$n��"
                       "���������Ҫ�ú��ˣ������������ߡ���\n", this_object(), me);
        return 1;
}
