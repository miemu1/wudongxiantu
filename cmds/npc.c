#include <ansi.h>
inherit CLASS_D("generate") + "/chinese";

void create()
{
	
	::create();
	set("gender", "����" );
	set("age", 18);
	set("long", "��������������һ�����֣�");
	
	
}

int accept_kill(object ob)
{
    object me=this_player();
	set("mrt/sj",time());
	command("say �Ǿ����ɣ���");
	return 1;
}

int accept_fight(object ob)
{
	return notify_fail("���˾����Ժøߣ����������֡�\n");
}

int accept_hit(object ob)
{

   return notify_fail("���˾����Ժøߣ����������֡�\n");
}

int accept_ansuan(object ob)
{
	return notify_fail("���˾����Ժøߣ����������֡�\n");
}

int accept_touxi(object ob)
{
	return notify_fail("���˾����Ժøߣ����������֡�\n");
}

void die()
{
int times;
int exp,pot,mar,mjf;
object me,obj;
me=this_object()->query_last_damage_from();
times=time()-query("mrt/sj");
me->set("mrt/sjs",times);
me->add("mrt/nd",2);  //����ǿ��

exp=1000+random(1000);
me->add("combat_exp", exp);
pot=1000+random(500);
me->add("potential", pot);
mar=1000+random(250);
me->add("experience", mar);	
mjf=1+random(3);
me->add("mjf", mjf);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ��������ˣ�"+exp+"����Ϊ��"+pot+"��Ǳ�ܣ�"+mar+"��ʵս��"+mjf+"���ؼ���ȯ��\n");

if(me->query("mrtnd")>3&&1==random(3)){
if(3==random(2)){
obj=new("/d/city/book/jin_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}else
if(6==random(2)){
obj=new("/d/city/book/yan_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}else
if(9==random(2)){
obj=new("/d/city/book/chun_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}
}else
if(me->query("mrtnd")>5&&1==random(3)){
if(2==random(2)){
obj=new("/d/city/book/yuan_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}else
if(4==random(2)){
obj=new("/d/city/book/wan_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}else
if(6==random(2)){
obj=new("/d/city/book/ba_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}else
if(8==random(2)){
obj=new("/d/city/book/zui_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}else
if(10==random(2)){
obj=new("/d/city/book/yin_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}else
if(12==random(2)){
obj=new("/d/city/book/ru_sui");
obj->move(me);
tell_object(me,"��ϲ����ս�����õ�"+me->query("mrtnd")+"��ɹ�������Ļ���ˣ�"+obj->name()+"������\n");
}
}



log_file("adm/mrt",sprintf("%s=%d\n",me->name(),times));	
me->move("/d/city/mingrt");
message("channel:chat",HBRED"�������á�"HBRED""+me->name()+"��ս����������ʤ����\n"NOR,users());	
shout(HBRED""+me->name()+"��ս����������ʤ����"NOR"\n");	
return ::die();
}

void unconcious()
{
	die();
}
