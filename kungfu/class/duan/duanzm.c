// duanzm.c 段正明

#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;

mixed ask_jue();
mixed ask_s1();
mixed ask_s2();
mixed ask_s3();
mixed try_to_learn_six();

void create()
{
	set_name("段正明", ({ "duan zhengming", "duan" }));
	set("title",  "大理国王" );
	set("long", "他就是大理国的国王，继承这近三百年的基业。\n");
	set("gender", "男性");
	set("age", 49);
	set("class", "royal");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 32);
	set("int", 35);
	set("con", 32);
	set("dex", 29);

	set("max_qi", 5800);
	set("max_jing", 3000);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 100);
	set("combat_exp", 2250000);
	set("score", 60000);

	set_skill("force", 250);
	set_skill("dodge", 240);
	set_skill("parry", 250);
	set_skill("cuff", 240);
	set_skill("sword", 240);
	set_skill("staff", 240);
	set_skill("finger", 250);
	set_skill("qimai-liuzhuan", 380);
	set_skill("duanshi-xinfa", 250);
	set_skill("tiannan-step", 240);
	set_skill("jinyu-quan", 240);
	set_skill("duanjia-sword", 240);
	set_skill("sun-finger", 250);
      set_skill("six-finger", 250);
	set_skill("literate", 180);

	map_skill("force", "duanshi-xinfa");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("finger", "sun-finger");

        set("no_teach", ([
                "six-finger"  : (: try_to_learn_six :),
        ]));

	set("inquiry", ([
		"段家五绝剑" : (: ask_jue :),
            "无形剑气"     : (: ask_s1 :),
            "六脉剑气"     : (: ask_s2 :),
            "六脉纵横"     : (: ask_s3 :),
	]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.dian" :),
		(: perform_action, "sword.jing" :),
		(: perform_action, "sword.jue" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);

	create_family("段氏皇族", 15, "传人");
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query_skill("duanshi-xinfa", 1) < 100)
	{
		command("say 你先好好学习我们段家的心法，以后我再指点你。");
		return;
	}

	if (ob->query("combat_exp") < 200000)
	{
		command("say 你现在实战修为太低了，好好在江"
			"湖上历炼，不要失了我们段氏的面子。\n");
		return;
	}

	command("say 好，我收下你了，不过武技固然重要，也不"
		"要忘记读书治国啊。");
	command("recruit " + ob->query("id"));
	return;
}

mixed ask_jue()
{
	object me;

	me = this_player();
	if (me->query("can_perform/duanjia-sword/jue"))
		return "你不是已经学会了五绝剑么？还有什么疑问么？";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你又不是我们段家的传人，这是什么意思？";

	if (me->query("shen") < 0)
		return "算了吧，传你绝招只怕你又去作恶！";

	if (me->query_skill("duanjia-sword", 1) < 100)
		return "你的段家剑法还不行，练练再说吧！";

	message_vision(HIC "$n" HIC "点点头，忽然欺上前来，以"
		       "手为剑连出几招，招式精奇无比，$N"
		       HIC "大吃一惊，只能后退。"NOR"\n",
		       me, this_object());
	command("smile");
	command("say 你看清楚了么？以后多要行侠仗义，莫要胡作非为！");
	tell_object(me, HIG "你学会了段家五绝剑。"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 90000);
	me->set("can_perform/duanjia-sword/jue", 1);
	return 1;
}

mixed try_to_learn_six()
{
        object ob = this_player();

        if (ob->query("family/family_name") != "段氏皇族")
        {
                command("say 你又不是我段家的人！");
                return -1;
        }

        if ((int)ob->query("score") < 10000)
        {
                command("hmm");
                command("say 你的江湖阅历太低了！");
                return -1;
        }

        if ((int)ob->query("shen") < 10000)
        {
                command("hmm");
                command("say 你的正神太低了！");
                return -1;
        }

	if ((ob->query("combat_exp") < 800000))
	{
                command("hmm");
                command("say 你的修为不足80W！");
                return -1;
	}

      if (ob->query_skill("duanshi-xinfa", 1) >= 200)
        {

                command("haha");
                command("say 想不到后辈中居然还有你这样的人物。");
                command("say 这套六脉神剑乃本族神技，今日我就传授予你。");
                ob->set_temp("can_learn/duanzm/six-finger", 1);
             return 0;
        }
        return "六脉神剑我不轻易传授";
}

mixed ask_s1()
{
	object me;

	me = this_player();
	if (me->query("can_perform/six-finger/qi"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们段家的人，打听我的武功想要干什么？";

	if (me->query_skill("six-finger", 1) < 180)
		return "就你这点本事？等你把六脉神剑练过180级再来找我吧！";

	tell_object(me, HIG "你学会了无形剑气。"NOR"\n");
	me->set("can_perform/six-finger/qi", 1);
	return 1;
}
mixed ask_s2()
{
	object me;

	me = this_player();
	if (me->query("can_perform/six-finger/six"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们段家的人，打听我的武功想要干什么？";

	if (me->query_skill("six-finger", 1) < 350)
		return "就你这点本事？等你把六脉神剑练过350级再来找我吧！";

	tell_object(me, HIG "你学会了六脉剑气。"NOR"\n");
	me->set("can_perform/six-finger/six", 1);
	return 1;
}
mixed ask_s3()
{
	object me;

	me = this_player();
	if (me->query("can_perform/six-finger/zongheng"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们段家的人，打听我的武功想要干什么？";

	if (me->query_skill("six-finger", 1) < 120)
		return "就你这点本事？等你把六脉神剑练过120级再来找我吧！";

	tell_object(me, HIG "你学会了无形剑气。"NOR"\n");
	me->set("can_perform/six-finger/zongheng", 1);
	return 1;
}
