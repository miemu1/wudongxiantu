#include <ansi.h>
#include "baiyun.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

mixed ask_skill1();

void create()
{
        set_name("��Ѫ", ({"bai xue","bai",}));
        set("long",
                "��š�����Ψһһ���������Ŵ�ѩ��Ҷ�³�ǿ��ͷ���ˡ�\n"
        );
        set("gender", "����");
        set("nickname", HIR "���" NOR);
        set("title", "����С��");
        set("attitude", "friendly");

        set("age", 30);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 30000);
        set("max_jing", 27000);
        set("neili", 30500);
        set("max_neili", 30500);
        set("jiali", 50);
        set("combat_exp", 5000000);

         set_skill("parry", 1200);
        set_skill("dodge", 1800);
        set_skill("force", 1020);
        set_skill("literate", 1200);
	set_skill("sword", 1200);
	set_skill("unarmed",1200);
	set_skill("changquan",1200);
	set_skill("feixian-steps",1200);
	set_skill("feixian-sword",1200);
	set_skill("jingyiforce",1020);

        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");

        create_family("���Ƴ�", 2, "����");

        set("inquiry", ([
                "��ʦ"        : "�ٺ٣�",
                "�������"    : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.dian" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/d/city/npc/obj/cloth")->wear();
        carry_object("/d/city/npc/obj/changjian")->wield();
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;


       

        if ((int)me->query("shen") > 1000)
        {
                command("heng");
                command("say ���ǹ�ɽ���Ƴ��������ʽ����£�Ҳ���ύ������������֮ʿ��");
                return;
        }

        if ((int)me->query("shen") < -1000)
        {
                command("heng");
                command("say �Ұ��Ƴ��������ʽ����£�������ύ��������֮�ˡ�");
                return;
        }

        command("say �ðɣ���Ȼ���������䣬�Ҿ������㡣");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jidian-jian/dian"))
                return "�̵ܽ����Ѿ��������ˡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("jidian-jian", 1) < 1)
                return "�������罣����ûѧ����̸���ԣ�";


        if (me->query_skill("jidian-jian", 1) < 100)
                return "��ļ��罣�������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 100)
                return "����ڹ�����в���������ѧ�������еġ�";

        message_vision(HIY "$n" HIY "���˵�ͷ��˵�����⼲�罣���ĵ��"
                       "������ʵ����������ʹ������ʩ��\n�������������"
                       "��ʾһ�飬��ɿ����ˡ�$n" HIY "˵�����г���һ"
                       "���������׽�\n��ʩչ��������ʱ֮�䣬���Ҷ��ǵ�"
                       "�⣬ҫ����Ŀ��$N" HIY "����˫Ŀһ������ʱ\n��"
                       "������\n" NOR, me, this_object());
        command("nod");
        command("say ������ʵ�ܼ򵥣���΢���������ʩչ�ˡ�");
        tell_object(me, HIC "��ѧ���ˡ�������䡹��\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500);
        if (me->can_improve_skill("jidian-jian"))
                me->improve_skill("jidian-jian", 1500);
        me->improve_skill("martial-cognize", 1500);
        me->set("can_perform/jidian-jian/dian", 1);


        return 1;
}
