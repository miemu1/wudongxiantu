#include <ansi.h>

inherit COMBINED_ITEM_BANG;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;
	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIR"��Ԫ"NOR, ({"long yuan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 111111);
            set("no_sell",1);
			set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
		set("no_shop", 1);//�¼�
        set("no_give", 1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10000);
		set("long","����������Ѫ�ľ�������˵����ʮ�ſ��Ի�úʹ�ͨ�澭����һ�������Լӳ�Ч��,Ҳֻ�ܷ���ʮ�š�\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i;
	string chuan;
	string *order = ({""HIG"", ""HIY"", ""HIC"", ""GRN"", ""HIR"", ""CYN"", ""HIW"", ""HIM""});
	string *name = ({	"�����˺�",		"�����Ѫ",		"���������ȼ�",		"���������ȼ�", 		"����", 		 "����",		 "�Ƽ�", 		 "����"	});		
	string *shuzi = ({		   465,		     9200,		        285,		            385, 	          60, 		        35,		      365, 		   365,});		
	string *daima = ({ "damage",     "max_qi",	    "defense",		   "attack", 		      "2ap", 	      "2dp",      "break",    "armor"	});	

  if (me->is_busy())
                return notify_fail("����æ���ء�\n");
	if (!me->query("beat"))
                return notify_fail("�����ͨ�澭�����ٷ��ðɣ�\n");
                
	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");
		    
	if(me->query("gift/longyuan")>= 10)
	{
		tell_object(me,"һ��һ��ֻ��ʹ��10�ţ�\n");
		return 1;
	}
	
	write(YEL"���˹�����"HIR"��Ԫ"YEL"����������ʱ����������"NOR"\n");
	
	for(i=0;i<8;i++)
	{
	chuan="gain/"+daima[i];	
	write(""+order[i]+"ԭ"+name[i]+"����ֵ:"+me->query(chuan)+"������"+shuzi[i]+","NOR);	
	me->add(chuan,shuzi[i]);
	write(""+order[i]+"����ֵ��"+me->query(chuan)+"��"NOR"\n");	
	}
	me->add("gift/longyuan", 1);
	i=me->query("gift/longyuan");
	write("���Ѿ�������"+me->query("gift/longyuan")+"����Ԫ�������Է���"+(10-i)+"�š�"NOR"\n");	
	add_amount(-1);
	return 1;
}

