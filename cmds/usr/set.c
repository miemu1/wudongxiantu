// set.c
#include <ansi.h>

#define MAX_ENV_VARS	40
 
int help();

#define LIST_TERM	       1
#define STRING_TERM	     2
#define NUMBER_TERM	     4
#define NON_ZERO		8
#define ENABLE_COLOR	    16
#define NON_NEG		 0x10
#define WIZ_ONLY		0x80

mapping query_terms() { return ([
	"auto_ban"	  : LIST_TERM,
	"auto_drinkout"   : 0,
	"auto_invite"	  : LIST_TERM,
	"auto_regenerate" : 0,
	"auto_say"	: 0,
	"no_vip"	: 0,
	"brief"	   : 0,
	"nocha_skills"	   : 0,
	"combatd"	 : 0,
	"combatd2"	 : 0,
	"careful"	 : 0,
	"can_accept"      : LIST_TERM,
	"can_emote"       : LIST_TERM,
	"can_snoop"       : LIST_TERM,
	"can_tell"	: LIST_TERM,
	"default_sign"    : NUMBER_TERM | NON_NEG | NON_ZERO,
	"halt_age"	: 0,
	"jam_talk"	: 0,
	"keep_idle"       : 0,
	"no_tan"       : 0,	
	"no_give_me"       : 0,	//�Է��ܾ�
	"no_exp"       : 0,	
	"no_new_hp1"	: 0,//�µ�Ѫ��״̬����ʾ��ʽ 0�ر� 1����
	"look_window"     : 0,
	"no_accept"       : LIST_TERM,
	"no_autoultra"    : 0,
	"no_emote"	: LIST_TERM,
	"no_more"	 : 0,
	"no_teach"	: 0,
	"no_tell"	 : LIST_TERM,
	"no_story"	: 0,
	"no_show"	: 0,
	"no_follow"       : 0,
	"prompt"	  : 0,
	"public"	  : 0,
	"pure_say"	: 0,
	"sign1"	   : STRING_TERM,
	"sign2"	   : STRING_TERM,
	"sign3"	   : STRING_TERM,
	"sign4"	   : STRING_TERM,
	"sign5"	   : STRING_TERM,
	"wimpy"	   : 0,
	"yuanshen"	   : 0,
	"hpp"	   : 0,
	"hppp"	   : 0,
	"yuanshenk"	   : 0,

	"wimpy_apply"     : 0,
	"combat_test"     : WIZ_ONLY,
	"invisible"       : WIZ_ONLY,
	"immortal"	: WIZ_ONLY,
	"msg_out"	 : WIZ_ONLY | STRING_TERM | ENABLE_COLOR,
	"msg_in"	  : WIZ_ONLY | STRING_TERM | ENABLE_COLOR,
	"no_prefix"	  : WIZ_ONLY,
]); }

mapping query_env_domains() { return ([
	"combatd" : ([
		"normal" : 0,
		"damage" : 1,
		"brief"  : 2,
		"self"   : 3,
		"null"   : 4,
		"new"   : 5,
	]),
	"combatd2" : ([
		"all" : 0,
		"self"   : 1,
	]),
	"jam_talk" : ([
		"none" : 0,
		"half" : 1,
		"abs"  : 2,
	]),
]); }

int main(object me, string arg)
{
	int i,num;
	int k;
	mapping env_domains;
	string msg;

	mapping term_map;
	string *terms;
	string term;
	mixed data;
	mapping env;
	mapping d;
	string *ks;
	mixed *bs;

	int opt_add, opt_del;
 
	env = me->query("env");

	term_map = query_terms();
	env_domains = query_env_domains();
 
	if (! arg || arg == "")
	{
		msg = "��Ŀǰ�趨�Ļ��������У�\n";
		if (! mapp(env) || ! sizeof(env))
			msg = "��Ŀǰû���趨�κλ���������\n";
		else
		{
			terms = sort_array(keys(env), 1);
			for (i = 0; i < sizeof(terms); i++)
			{
				if (mapp(d = env_domains[terms[i]]))
				{
					ks = keys(d);
					for (k = 0; k < sizeof(ks); k++)
						if (d[ks[k]] == env[terms[i]])
							break;
					if (k < sizeof(ks))
					{
						msg += sprintf("%-20s  %O\n",
						       terms[i], ks[k]);
						continue;
					}
				}
				msg += sprintf("%-20s  %O\n", terms[i], env[terms[i]]);
			}
		}
		write(msg);
		return 1;
	}
 
	if(arg=="sign5")
	{
		write(INPUTTXT("������Ҫ�Զ�ѭ��ִ�е�����������飺$br#�������ʽΪ�ֺ����ӵ�5���������","set sign5 $txt#")+"\n");
		return 1;
	} else
	if (arg == "nocha_skills")
	{
		msg = ZJOBLONG"�����趨��";
		msg += NOR"\n"ZJOBACTS2+ZJMENUF(1,1,10,32);
		msg += "�Զ�����-��ǰ�趨�� "HIG+me->query("env/wimpy")+NOR"%:set wimpy"ZJSEP;			
		if (me->query("env/nocha_skills"))
		msg += "չʾ����-��ǰ�趨�� "HIG"����"NOR":unset nocha_skills"ZJSEP;
		else		
		msg += "չʾ����-��ǰ�趨�� "HIR"������"NOR":set nocha_skills 1"ZJSEP;	
		if (me->query("env/keep_idle"))		
		msg += "��������-��ǰ�趨�� "HIG"������"NOR":unset keep_idle"ZJSEP;
		else
		msg += "��������-��ǰ�趨�� "HIR"����"NOR":set keep_idle 1"ZJSEP;	
		if (me->query("env/auto_regenerate"))		
		msg += "�Զ�����-��ǰ�趨�� "HIG"�Զ�"NOR":unset auto_regenerate"ZJSEP;
		else
		msg += "�Զ�����-��ǰ�趨�� "HIR"���Զ�"NOR":set auto_regenerate 1"ZJSEP;
		if (me->query("env/no_exp"))		
		msg += "ʦ�Ż�ȡ��Ϊ-��ǰ�趨�� "HIR"����ȡ"NOR":unset no_exp"ZJSEP;
		else
		msg += "ʦ�Ż�ȡ��Ϊ-��ǰ�趨�� "HIG"��ȡ"NOR":set no_exp 1"ZJSEP;	
		if (me->query("env/no_tan"))		
		msg += "˽�ĵ���-��ǰ�趨�� "HIR"�ر�"NOR":unset no_tan"ZJSEP;		
		else		
		msg += "˽�ĵ���-��ǰ�趨�� "HIG"����"NOR":set no_tan 1"ZJSEP;	
	
		if (me->query("env/no_new_hp1"))		
			msg += "��ս��״̬-��ǰ�趨�� "HIG"�ѿ���"NOR":unset no_new_hp1"ZJSEP;		
		else		
			msg += "��ս��״̬-��ǰ�趨�� "HIR"δ����"NOR":set no_new_hp1 1"ZJSEP;	
		
		
		if (me->query("env/no_give_me"))		
			msg += "�ܾ����նԷ���Ʒ-��ǰ�趨�� "HIG"�ѿ���"NOR":unset no_give_me"ZJSEP;		
		else		
			msg += "�ܾ����նԷ���Ʒ-��ǰ�趨�� "HIR"δ����"NOR":set no_give_me 1"ZJSEP;	
		if (me->query("env/yuanshen"))		
			msg += "��������Ԫ���˺�-��ǰ�趨�� "HIG"�ѿ���"NOR":set yuanshen 0"ZJSEP;		
		else		
			msg += "��������Ԫ���˺�-��ǰ�趨�� "HIR"δ����"NOR":set yuanshen 1"ZJSEP;		
		if (me->query("env/hpp"))		
			msg += "����״̬����ʾ-��ǰ�趨�� "HIG"�������°�"NOR":set hpp 0"ZJSEP;		
		else		
			msg += "����״̬����ʾ-��ǰ�趨�� "HIR"�����þɰ�"NOR":set hpp 1"ZJSEP;		
		if (me->query("env/hppp"))		
			msg += "ʦ��ˢ��-��ǰ�趨�� "HIG"��ˢ��"NOR":set hppp 0"ZJSEP;		
		else		
			msg += "ʦ��ˢ��-��ǰ�趨�� "HIR"ˢ��"NOR":set hppp 1"ZJSEP;		
		if (me->query("env/yuanshenk"))		
			msg += "����Ԫ���˺�ˢ��-��ǰ�趨�� "HIG"������"NOR":set yuanshenk 0"ZJSEP;		
		else		
			msg += "����Ԫ���˺�ˢ��-��ǰ�趨�� "HIR"����"NOR":set yuanshenk 1"ZJSEP;		
		write(msg + "\n");
		return 1;
	} 	else if(arg=="wimpy")
	{
		return notify_fail(INPUTTXT("����Ѫ�����ڶ��ٰٷֱ�ʱ�����Զ����ܣ�","set wimpy $txt#")+"\n");
	} 
	else if(sscanf(arg,"wimpy %d",num)==1)
	{
		me->set("env/wimpy",num);
		me->force_me("set nocha_skills");
		return 1;
	}else
	if(arg=="combatd")
	{
		msg = ZJOBLONG"��Ŀǰ����ս����Ϣ��ʾ��ʽΪ��"ZJBR HIG;
		if(me->query("env/combatd")==1) msg += "���˺�ʱ��ʾս����Ϣ";
		else if(me->query("env/combatd")==2) msg += "ֻ��ʾ˫��������Ϣ";
		else if(me->query("env/combatd")==3) msg += "ֻ��ʾ�Լ���������Ϣ";
		else if(me->query("env/combatd")==4) msg += "����ʾ�κ�ս����Ϣ";
		else if(me->query("env/combatd")==5) msg += "���ֻ�������ʾս����Ϣ";
		else msg += "��ʾ����ս����Ϣ";
		msg += NOR ZJBR"��Ŀǰ����ս����Ϣ��ʾ��ʽΪ��"ZJBR HIG;
		if(me->query("env/combatd2")==1) msg += "����ʾ����ս����Ϣ";
		else msg += "��ʾ����ս����Ϣ";

		msg += NOR"\n"ZJOBACTS2+ZJMENUF(2,2,10,32);
		msg += "��ʾ����ս����Ϣ:set combatd normal"ZJSEP;
		msg += "���˺�ʱ��ʾս����Ϣ:set combatd damage"ZJSEP;
		msg += "ֻ��ʾ˫��������Ϣ:set combatd brief"ZJSEP;
		msg += "ֻ��ʾ�Լ���������Ϣ:set combatd self"ZJSEP;
		msg += "����ʾ�κ�ս����Ϣ:set combatd null"ZJSEP;
		msg += "���־�����ʾս����Ϣ:set combatd new"ZJSEP;
		msg += "��������ս����Ϣ:set combatd2 self"ZJSEP;
		msg += "��ʾ����ս����Ϣ:set combatd2 all";
		write(msg + "\n");
		return 1;
	}

	opt_add = 0;
	opt_del = 0;
	if (sscanf(arg, "%s -a %s", term, data) == 2 ||
	    sscanf(arg, "-a %s %s", term, data) == 2)
	{
		opt_add = 1;
	} else
	if (sscanf(arg, "%s -d %s", term, data) == 2 ||
	    sscanf(arg, "-d %s %s", term, data) == 2)
	{
		opt_del = 1;
	} else
	if (sscanf(arg, "%s %s", term, data) != 2)
	{
		term = arg;
		if (term_map[term] & STRING_TERM ||
		    term_map[term] & NUMBER_TERM)
			return notify_fail("�����ָ�������������"
					   "�ݣ��������� unset ȡ�����������\n");
		else
			data = "YES";
	}
 
	if (data == "")
		return notify_fail("�趨�Ĳ���ֵ����Ϊ�ա�\n");

	if (term_map[term] & NUMBER_TERM)
	{
		sscanf(data, "%d", data);
		if (! intp(data)) data = 0;
		if ((term_map[term] & NON_ZERO) && ! data)
			return notify_fail("�������ֵ��������Ϊ�㡣\n");

		if ((term_map[term] & NON_NEG) && data < 0)
			return notify_fail("�������ֵ��������Ϊ������\n");
	} else
	if (term_map[term] & STRING_TERM &&
	    term_map[term] & ENABLE_COLOR)
	{
		data = color_filter(data);
		if (strsrch(data, ESC) != -1)
			data += NOR;
	}

	if (term && term != "")
	{
		if (mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS)
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");

		if (undefinedp(term_map[term]))
			return notify_fail("��ֻ���趨�涨�Ĳ�������μ�help settings��\n");

		if ((wiz_level(me) == 0) && (term_map[term] & WIZ_ONLY))
			return notify_fail("ֻ����ʦ��������趨��\n");

		if (term_map[term] & LIST_TERM)
		{
			if (! stringp(data) || data == "YES")
				return notify_fail("�б����ֻ�����ַ���Ϊȡֵ��\n");

			ks = explode(data, ",") - ({ "" });
			bs = ({ });
			for (i = 0; i < sizeof(ks); i++)
			{
				if (member_array(ks[i], bs) == -1)
					bs += ({ ks[i] });
			}
			data = implode(bs, ",");
		}

		if (opt_add || opt_del)
		{
			if (! (term_map[term] & LIST_TERM))
				return notify_fail("��������������б����ԣ���"
						   "��ʹ��-a������-d������\n");
			if (opt_add)
				data = add_sub(data, me->query("env/" + term));
			else
				data = remove_sub(data, me->query("env/" + term));
			if (strlen(data) > 256)
				return notify_fail("����ȡֵ̫���ˡ�\n");

			if (! data)
			{
				me->delete("env/" + term);
				write("ȡ������������" + term + "\n");
				return 1;
			}
		}

		if (mapp(d = env_domains[term]))
		{
			if (! undefinedp(d[data])) data = d[data];

			// check the data
			ks = keys(d);
			for (k = 0; k < sizeof(ks); k++)
				if (d[ks[k]] == data) break;
			if (k >= sizeof(ks))
			{
				write("��������������óɸ�ֵ����μ�help settings��\n");
				return 1;
			}
			me->set("env/" + term, data);
			write(sprintf("�趨����������%s = %O\n", term, ks[k]));
			return 1;
		} else
		if (stringp(data) && ! (term_map[term] & LIST_TERM) &&
		    ! (term_map[term] & STRING_TERM))
			sscanf(data, "%d", data);

		me->set("env/" + term, data);
		write(sprintf("�趨����������%s = %O\n", term, data));

		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
ָ���ʽ��set <������> -a | -d [<����>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"�����ʹ����-a��������ʾ���������뵽ԭ�еĲ����У�
���ʹ����-d�������ʾ��������ԭ�еĲ�����ȥ����ֻ�о��ж�ֵ���ԵĲ�������
ʹ��������������

����no_tell�����������趨Ϊ������test��work�Ľ�����
set no_tell test,work

�����ʱ���㲻ϣ������nothing�Ľ���������ԣ�
set no_tell -a nothing  Ҳ���ԣ�set no_tell test,work,nothing

�����ʱ����ϣ������test�Ľ���������ԣ�
set no_tell -d test     Ҳ���ԣ�set no_tell work,nothing

ȡ�������趨���� unset ָ�

�������Щ�������������趨����� help settings��
TEXT
	);
	return 1;
}
