//����ɽ���ɡ�dhxy-evil 2000.7.5
//yushu�޸� 2001.2
#include <ansi.h>
#include "shushan.h"
inherit NPC;

#define YAO       "/d/shushan/obj/lingyao"

int do_report();
void create()
{
        set_name("����ң", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","��ɽ�����ŵ���");
        set("long", 
           "����ң��Ľ��ݣ�����Ũü���ۣ������Ѱ���\n");
        set("gender", "����");
        set("age", 18);
	      set("class", "xiake");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("qi", 2800);
        set("max_qi", 2800000);
        set("jing", 160000);
        set("max_jing", 160000);
        set("neili", 480000);
        set("combat_exp", 100000000);
        set("max_jingli", 10000);
        set("max_neili", 100000);
        set("jingli", 100000);
        set("neili",10000000);
         set("jiali",1000);
        set_skill("force", 800);
        set_skill("dodge", 800);
        set_skill("unarmed", 800);
         set_skill("fumozhang", 800);
        set_skill("parry", 800);
        set_skill("sword", 800);
        set_skill("spells", 800);
        set_skill("xianfeng-spells", 800);
        set_skill("yujian-shu", 800);
        set_skill("shushan-force", 800);
        set_skill("zuixian-steps",800);
        set_skill("literate",800);
        map_skill("unarmed", "fumozhang");
        map_skill("spells", "xianfeng-spells");
        map_skill("force", "shushan-force");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "yujian-shu");
	  set("chat_chance",20);
       
    set("chat_msg",({
        "����ң��߶�ţ���! ��֪����Ů���᲻�������ҩ��\n",
        "����ң�����̾�˿�����\n",
        "����ң����˵����˭�ܾȾ���������\n"
       }) );
        set("inquiry", ([
                "�ȳ�����"    : (: do_report :),
        ]));
	 setup();
        create_family("��ɽ��", 3, "����");
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="��ɽ��" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
			else command("say ʦ�ü�Ц�ˡ�\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
			else command("say ʦ��̫�����ˡ�\n");
		}
		else 
		{
			command("consider");
			command("say ��������ĳ���ķ���,������Ϊͽ!\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say ��������ĳ���ķ���,������Ϊͽ!\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ������ң����");
              }
              return 0;
}
void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "����ң˵������λ" + RANK_D->query_respect(ob) +
"���ܲ��ܰ��Ҿȳ�����������ؽ����������ˣ�\n");
}


int do_report()
{
 int i=random(50000)+1;
 object me = this_player();
 if(me->query("shushan/zhanyi")) { 
 me->set("zhanyi/zhenyaota",1);
 me->delete("shushan/zhanyi");
 me->add("combat_exp",500000);
 me->add("potential",100000);
 me->add("max_neili",me->query("max_neili")/10);
 message("system",HIC"��"HIW"��������Ѷ"HIC"��"HIY+me->query("name")+HIG"�ȳ�[1;37m������[1;32m�����������ܵ�������[2;37;0m\n"NOR,users());    
 tell_object(me,"��Ӯ����"+chinese_number(500000)+"����Ϊֵ��"+chinese_number(100000)+"��Ǳ��,��������10%������\n");
 me->save();
 } 
 else 
 {
 command("say лл�㣡�������鷳������");
 }
 return 1;
}


int accept_object(object me, object obj)
{
object tuzhu;
if(base_name(obj)!=YAO)
{
                command("say �ⶫ�����κ��������Ĳ����㲻Ҫƭ����!\n");
                return 0;
}
	tuzhu=new("/d/shushan/zhenyaota/obj/tuzhu");
	tuzhu->move(me);
	command("say �����������о���!! ���������͸���ɡ�\n");
return 1;

}

