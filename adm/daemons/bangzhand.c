#include <ansi.h>
inherit F_SAVE;
inherit F_DBASE;
nosave int bangzhan;
string query_save_file()
{
	return DATA_DIR "bangzhan";
}

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "��սϵͳ");
	CHANNEL_D->do_channel( this_object(), "sys", "��սϵͳ�Ѿ�������");
	restore();
	set_heart_beat(20);
}
void heart_beat()
{
	mixed* r;
	object ob,a1;	
	int i;
	int exps,pots,mots;
	string short;
	object *inv;
	object *players;
	int time = time();
	r = localtime(time);
	if(r[1]==35&&r[2]==21&&bangzhan!=1)
	{
	a1= find_object("d/city/bang/a1");
	if(!a1) a1 = load_object("d/city/bang/a1");
	a1->set("bangzhan",1);
    ob=new("d/city/bang/npc/sho");
	ob->set("name","�ػ���");
	ob->move(a1);	
    CHANNEL_D->do_channel(this_object(), "chat", HIY"��ս�������ػ��߽��٣�"NOR"");
	shout(HIY"��ս�������ػ��߽��٣�"NOR"\n" );	
	bangzhan=1;
	}
	if(r[1]==15&&r[2]==22)
	{
	a1= find_object("d/city/bang/a1");
	if(!a1) a1 = load_object("d/city/bang/a1");
	a1->delete("bangzhan");
    inv = all_inventory(a1);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="sho"&&!userp(inv[i])&&inv[i]->query("bangzhansho")==1)
		{
           destruct(inv[i]);
		}
	}
	//��ʤ�İ���������һ�ý�����by name
	if(short=a1->query("shendishohu")&&a1->query("shendishohu"))
	{	
	 players = users();              
     for(i = 0; i<sizeof(players); i++){     
     if(short==players[i]->query("banghui/name")){
     exps=10000+random(10000);
     pots=10000+random(5000);
     mots=5000+random(5000);
     players[i]->add("potentiexp",pots);
     players[i]->add("combat_exp",exps);
     players[i]->add("experience",mots);
     tell_object(players[i],HIW"��ϲ��İ��ɻ���˰���ս��ʤ����"+HIG+"����˻���ˣ�"+exps+"��Ϊ��"+pots+"Ǳ�ܣ�"+mots+"��ᡣ\n"NOR); 
     
     log_file("adm/bangzhan", sprintf("%s��"+short+"�����ʤ�����������߳�Ա��"+players[i]->name()+"������"+players[i]->query("banghui/name")+" ���ɳ�Ա��\n",ctime(time())));
	
     }
     }
	
	
	
	
    CHANNEL_D->do_channel(this_object(), "chat", HIY""+short+"���"+a1->query("short")+"����Ȩ��"NOR"");
	shout(HIY""+short+"���"+a1->query("short")+"����Ȩ��"NOR"\n" );	
	}
	else
	{
    CHANNEL_D->do_channel(this_object(), "chat", HIY""+a1->query("short")+"û�а��ɻ�ȡ��"NOR"");
	shout(HIY""+a1->query("short")+"û�а��ɻ�ȡ��"NOR"\n" );	
	}
	}
}

public int zhaohuan(object me)//�����ػ����ٻ������ػ�
{
	string short;
	object *inv;
	int i;
	object ob,a1;
	a1=environment(me);
    inv = all_inventory(a1);
	if(!me)
	{
	tell_object(me,"��ʽ����\n");
	return;
	}
	if(me->query("pet")==1)
	{
	tell_object(me,"���ܴ�������룡\n");
	return;
	}
	if(!(short=me->query("banghui/name")))
	{
	tell_object(me,"���а����𣿣�\n");
	return;
	}
	if(environment(me)->query("bangzhan")!=1||!environment(me)->query("bangzhan"))
	{
	tell_object(me,"���ǰ�ս�ĵط���\n");
	return;	
	}
    if(environment(me)->query("shendishohu")!=short)
	{
	tell_object(me,""+environment(me)->query("short")+"�����Ƕ����ˣ�\n");
	return;		
	}
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="sho"&&!userp(inv[i]))
		{
	    tell_object(me,"�˵��Ѿ����ػ��ߣ�\n");
	    return;	
		}
	}
    ob=new("d/city/bang/npc/sho");
	ob->set("name",HIY+short+HIR"�ػ���"+NOR);
	ob->set("bangpai",short);
	ob->move(a1);
    CHANNEL_D->do_channel(ob, "chat", HIY""+short+"�����ٻ��ػ��ߣ�"NOR"");
	shout(HIY""+short+"�����ٻ��ػ��ߣ�"NOR"\n" );	
	return;
};
