// tangltt

#include <ansi.h>
#include "tangmen.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER; 
inherit F_COAGENT;  

string ask_me();
mixed ask_th1();
mixed ask_th2();
mixed ask_th3(); 
mixed ask_th4(); 
mixed ask_ql(); 
mixed ask_by1(); 
mixed ask_by2(); 
mixed ask_wu(); 

void create()
{
        set_name("����̫̫", ({ "tang laotai", "tang" }));
        set("nickname", HIW "��������" NOR);
        set("long", 
                "���������ŵڶ�����������̫̫�������ľ�Ӫ�£�\n"
                "�����ڽ��������������Ժա�\n"
                "����Լ��ʮ���࣬һͷ������������档\n");
	set("gender", "Ů��");
	set("age", 72);
        set("class", "tangmen");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 8000);
        set("max_jingli", 1500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("max_jing",2000);
        set("jiali", 100);
        set("combat_exp", 2400000);
        set("level", 55);
        set("shen",3000);
        set("score", 7000);

        set_skill("force", 280);
        set_skill("throwing", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("literate", 280);
        set_skill("hand", 280);
        set_skill("sword", 280);
        set_skill("boyun-suowu", 280);
        set_skill("biyun-xinfa", 280);
        set_skill("qiulin-shiye", 280);
        set_skill("wuzhan-mei", 280);
        set_skill("poison", 280);
        set_skill("medical", 280);
        set_skill("medical", 280);
        set_skill("tangmen-throwing", 208);
        set_skill("tangmen-poison", 280);
        set_skill("tangmen-medical", 280);        
        
        map_skill("force", "biyun-xinfa");
        map_skill("throwing", "tangmen-throwing");
        map_skill("dodge", "qiulin-shiye");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");
        map_skill("hand", "boyun-suowu");
        map_skill("poison", "tangmen-poison");
        map_skill("medical", "tangmen-medical");
        
        prepare_skill("hand", "boyun-suowu");
        
        create_family("��������", 2, "����");
	set("inquiry", ([
                "��������" : (: ask_me :),	 
                "�ƻ�"     : (: ask_th1 :),
                "����ǧǧ��"     : (: ask_th2 :), 
                "ɢ����Ů"     : (: ask_th3 :),
                "���Ӹ���"     : (: ask_th4 :), 
                "������"     : (: ask_ql :), 
                "������"     : (: ask_by1 :), 
                "����"         : (: ask_by2 :), 
                "������Ӱ"     : (: ask_wu :),       
	]));
	
        set_temp("apply/damage", 100);  
        set_temp("apply/unarmed_damage", 100);  
        set_temp("apply/armor", 200);          

        set("master_ob", 4);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
        set_temp("handing", carry_object("/d/tangmen/obj/jili"));          
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))  
                return;
                        
        if ( (string)ob->query ("family/family_name") != "��������" || 
             (int)ob->query ("combat_exp") < 600000) 
	{
        	command("say �㻹���Ȱ���ȱΪʦ��ѧЩ���ŵĻ�������ɣ�\n");
                return;
        }

        if ((int)ob->query_skill("biyun-xinfa", 1) < 150) 
        {
                command("say ������Ȼ�԰���Ϊ����������Ҫ����������"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڱ����ķ��϶��µ㹦��");
                return;;
        }
        if ((int)ob->query("dex") < 30)
        {
                command("say �������̫���ˣ���Ҫ�����Լ�������\n");
                return;    
        }
        if ((int)ob->query("int") < 25) {
                command("say ��������ע�ص��ӵ���ѧ��Ϊ��");
                command("say ���ɹ���Ҫ���������ã��������������������Զ�⾳�����Բ����ǲ��еġ�");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }

        command("say �ðɣ��ӽ�����������ҵĹ��ŵ����ˡ�\n");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        object me;
        me = this_player();
        if (me->query_temp("marks/��"))
        {
                command("say ������Ʒ��Ǹ���Ѿͷ��̽��Ϣ�𣿿��Ҳ�������");
                command("hit " + me->query("id"));
                return "������̫�ŷǵý�ѵ��һ�²��ɡ�\n";
        }
        if (me->query_temp("marks/��"))
        {
                command("angry " + this_player()->query("id"));
                command("say �ѵ�����������ˮһ����������������\n");
                command("heng " + this_player()->query("id"));
                command("say �Ʒ��Ǹ���Ѿͷ��\n");
                this_player()->set_temp("marks/��", 1);
                me->delete_temp("marks/��");
                return"����ˮ�ѱ��ҹ������ˣ��������ټ��������С���ˣ�\n";
        }
        else
        {       
                return "�����ӣ���˵ɶ�ӣ���̫��������Ŷ��\n";
        }


}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;
        default:
                return 0;
        }
}

mixed ask_th1()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/hua"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("tangmen-throwing", 1) < 180)
		return "������㱾�£���������Ű�������180���������Ұɣ�";

	tell_object(me, HIG "��ѧ�����ƻ���"NOR"\n");
	me->set("can_perform/tangmen-throwing/hua", 1);
	return 1;
}
mixed ask_th2()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/qian"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("tangmen-throwing", 1) < 140)
		return "������㱾�£���������Ű�������140���������Ұɣ�";

	tell_object(me, HIG "��ѧ��������ǧǧ�ᡣ"NOR"\n");
	me->set("can_perform/tangmen-throwing/qian", 1);
	return 1;
}
mixed ask_th3()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/san"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("tangmen-throwing", 1) < 160)
		return "������㱾�£���������Ű�������160���������Ұɣ�";

	tell_object(me, HIG "��ѧ����ɢ����Ů��"NOR"\n");
	me->set("can_perform/tangmen-throwing/san", 1);
	return 1;
}
mixed ask_th4()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/biao"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("tangmen-throwing", 1) < 120)
		return "������㱾�£���������Ű�������120���������Ұɣ�";

	tell_object(me, HIG "��ѧ�������Ӹ��ڡ�"NOR"\n");
	me->set("can_perform/tangmen-throwing/biao", 1);
	return 1;
}
mixed ask_ql()
{
	object me;

	me = this_player();
	if (me->query("can_perform/qiulin-shiye/wu"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("qiulin-shiye", 1) < 100)
		return "������㱾�£����������ʰҶ����100���������Ұɣ�";

	tell_object(me, HIG "��ѧ���������衣"NOR"\n");
	me->set("can_perform/qiulin-shiye/wu", 1);
	return 1;
}
mixed ask_by1()
{
	object me;

	me = this_player();
	if (me->query("can_perform/boyun-suowu/dian"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("boyun-suowu", 1) < 120)
		return "������㱾�£�����Ѳ�����������120���������Ұɣ�";

	tell_object(me, HIG "��ѧ���������㡣"NOR"\n");
	me->set("can_perform/boyun-suowu/dian", 1);
	return 1;
}
mixed ask_by2()
{
	object me;

	me = this_player();
	if (me->query("can_perform/boyun-suowu/meng"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("boyun-suowu", 1) < 160)
		return "������㱾�£�����Ѳ�����������160���������Ұɣ�";

	tell_object(me, HIG "��ѧ���˻��Ρ�"NOR"\n");
	me->set("can_perform/boyun-suowu/meng", 1);
	return 1;
}
mixed ask_wu()
{
	object me;

	me = this_player();
	if (me->query("can_perform/wuzhan-mei/liu"))
		return "��ú���ϰ�书����Ҫ���ҵ�����";

	if (me->query("family/family_name") != query("family/family_name"))
		return "�㲻�������Ƽҵ��ˣ������ҵ��书��Ҫ��ʲô��";

	if (me->query_skill("wuzhan-mei", 1) < 120)
		return "������㱾�£��������չ÷����120���������Ұɣ�";

	tell_object(me, HIG "��ѧ���˻��Ρ�"NOR"\n");
	me->set("can_perform/wuzhan-mei/liu", 1);
	return 1;
}

