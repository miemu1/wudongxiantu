//����ɽ�ɡ�mhxy-yushu 2001/2
inherit NPC;
inherit F_DEALER;
void create()
{
  set_name("���ϰ�", ({ "liu laoban", "liu", "laoban" }) );
  set("gender", "����");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "friendly");
  set("str", 30);
  set("max_qi", 200);
  set("max_gin", 200);
  set("neili", 200);
  set("max_neili", 200);
  set("jiali", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);
  setup();
//    carry_object("/d/qujing/tianzhu/obj/huapao")->wear();
}

