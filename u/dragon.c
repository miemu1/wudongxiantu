//�������� (�ı���12gong job)
//@txwx by hhm 06/07/01
inherit NPC;
#include <star.h>
void create()
{
        set_name(HIW"��������"NOR, ({"jiutou she", "guizi"}));
        set("long", "����������Ĺ�������Ϲ��������룬��̫���׺ݣ����ϹŰ�����ħ��ʦ������ץ���������޾���Ԩ��\n");
        set("gender","����");
        set("title", HIR"��boss��"NOR);
      set("no_get",1);
        set("age",37);
        set("attitude", "peaceful");
        set("con",1300);
        set("per",312);
        set("str",3250);
        set("int",3305);
        set("combat_exp",23000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "�������ޣ���\n" 
				"�������ޣ�������ʦ�����ҳ�ȥ��\n"
        }));
       set("max_neili", 6000000);
         set("neili", 6000000);
         set("max_jingli",6000000);
         set("jingli",6000000);
         set("jiali",6000000);
         set("max_qi", 6000000);
         set("max_jing", 6000000);
          set_skill("dodge", 550);
          set_skill("force", 550);
          set_skill("parry", 550);
          set_skill("unarmed", 600);
		  set_skill("wuxing-dun", 550+random(300));
		  set_skill("shaolin-shenfa", 600);
		  set_skill("qishang-quan", 600);
        create_family("boss��",1,"��������");
        set("chat_chance_combat", 1300);
        set("chat_msg_combat", ({
        (: perform_action, "sword.daya" :),
    }) );
        setup();
}
 
 void die()
{
        object nvh,obj1,env;
         object ob =  this_object()->query_last_damage_from();
            object *players;
         int w,x,i;
        ob->start_busy(1); 
		env = environment(this_object());
        if (sizeof(ob->query_team()) > 1)
        {
        players = ob->query_team();
        x = 5000;   
        }
        else
        {
        obj1 = new("/clone/boss/caifuyingbixiao");
		obj1->set_amount(1);
		obj1->move(env);
		ob->add("potential",12000);
        ob->add("combat_exp", 10000);
        ob->add("jifeng", 10);
        ob->add("experience", 100);
         tell_object(ob,HIR"��Ӯ������Ϊ10000,Ǳ��12000��10��ȯ��ʵս��᲻������."+w+"\n\n"NOR);   
         players = users();
         x = 1000;
         }
         w = sizeof(players);         
       for(i = 0; i<sizeof(players); i++)
         {
         players[i]->add("potential",x);
        players[i]->add("combat_exp", x/2);
        players[i]->add("experience", x/10);
       tell_object(players[i],HIR"����"+ob->query("name")+"�������������ޣ���Ӯ����"+x+"��Ϊ,"+x/2+"Ǳ�ܣ�"+x/10+"ʵս���.\n"NOR); 
       }
            message("channel:chat",HBRED"����boos��ս"HIR"��"+ob->query("name")+"�񹦸�������ɱ���������ޣ��������ֿ�ģ�����߹���"+w+"�����հ����\n"NOR,users());
       ::die();
}
