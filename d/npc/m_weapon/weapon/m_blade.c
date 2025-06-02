// m_blade.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
inherit S_WEAPON;

int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
	add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
}


void create()
{
	object me;
	string w_name,w_id,w_or,p_name,name;
	int w_lv,dj,color;
	me = this_player();
//��������
//�������������˵õ�����bug���������������Խ����
/*        if (!(me->query("weapon/name")))
{
                remove_call_out("destrory");
                call_out("destrory",1,me);
                return;
}*/
	w_name=me->query("weapon/name");
	w_id = "my "+me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
	dj = me->query("weapon/dj");
        color = w_lv / 2;

	p_name = HIY"��Ʒ"NOR;

	if (me->query("weapon/pin"))
	{
		p_name = me->query("weapon/pin");
	}
        switch(color){
                case 1:
                        name = WHT + p_name + w_name + NOR;
                        break;
                case 2:
                        name = HIR + p_name + w_name + NOR;
                        break;
                case 3:
                case 4:
                        name = HIB + p_name + w_name + NOR;
                        break;
                case 5:
                        name = HIY + p_name + w_name + NOR;
                        break;
                case 6:
                        name = HIM + p_name + w_name + NOR;
                        break;
                case 7:
                        name = MAG + p_name + w_name + NOR;
                        break;
                case 8:
                        name = HIW + p_name + w_name + NOR;
                        break;
                case 9:
                        name = HIC + p_name + w_name + NOR;
                        break;
                default:
                        name = HIG + p_name + w_name + NOR;
                        break;
        }
	if (!me->query("weapon/name"))
	{
		w_name="���Ƶĸֵ�";
	}
	if (!me->query("weapon/id"))
	{
		w_id="blade";
	}
	if (!me->query("weapon/or"))
	{
		w_or="ǧ����ľ";
	}
	if (!me->query("weapon/lv"))
	{
		w_lv=5;
	}
	if (!me->query("weapon/dj"))
	{
		dj=1;
	}
	/*if (me->query("weapon/lv",1) > 150)
	{
		w_lv=150;
	}*/

	set_name(name , ({w_id}));
	set("unit", "��");
	set("weapon_prop/baoji", w_lv * 2);
	set("weapon_prop/yuanshen", me->query("yuanshen/weapon"));
	set("pin",me->query("weapon/pin"));
	set("value",1000);
	set("ownmake",1);
	set("no_sell",1);
	set("no_give",1);
	set("no_get",1);

	set("no_drop",1);
	set("no_put",1);
	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "ǧ����ľ" :
			set_weight(500);
			set("material", "iron");
			break;
		case "���׽�ĸ" :
			set_weight(1000);
			set("material", "steel");
			break;
		case "��˿����" :
			set_weight(30);
			set("material", "bamboo");
			break;
		default :
		}
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	else
		set("wield_msg", "$N������һ���������һ��"+name+"�������С�\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
	else
		set("unwield_msg", "$N����"+name+"ӭ��һ����գ�ۼ���Ȼ����Ӱ�١�\n");
	if (!me->query("weapon/pin"))
		init_blade(w_lv * 10 *dj);
	else if (me->query("weapon/pin") == "��Ʒ")
		init_blade(w_lv * 15 *dj);
	else if (me->query("weapon/pin") == "��Ʒ")
		init_blade(w_lv * 18 *dj);
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 21 *dj);
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 22 *dj);
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 23 *dj);	
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 24 *dj);
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 25 *dj);
	else if (me->query("weapon/pin") == "ڤ��")
		init_blade(w_lv * 26 *dj);
	else if (me->query("weapon/pin") == "ʥ��")
		init_blade(w_lv * 27 *dj);
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 28 *dj);		
	else if (me->query("weapon/pin") == "ħ��")
		init_blade(w_lv * 29 *dj);		
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 30 *dj);		
	else if (me->query("weapon/pin") == "����")
		init_blade(w_lv * 31 *dj);		
	else if (me->query("weapon/pin") == "һ�׹���")
		init_blade(w_lv * 32 *dj);			
else if (me->query("weapon/pin") == "���׹���")
		init_blade(w_lv * 33 *dj);			
else if (me->query("weapon/pin") == "���׹���")
		init_blade(w_lv * 34 *dj);			
else if (me->query("weapon/pin") == "�Ľ׹���")
		init_blade(w_lv * 35 *dj);			
else if (me->query("weapon/pin") == "��׹���")
		init_blade(w_lv * 36 *dj);		
else if (me->query("weapon/pin") == "һ������")
		init_blade(w_lv * 37 *dj);	
else if (me->query("weapon/pin") == "��������")
		init_blade(w_lv * 38 *dj);	
else if (me->query("weapon/pin") == "��������")
		init_blade(w_lv * 39 *dj);	
else if (me->query("weapon/pin") == "�Ľ�����")
		init_blade(w_lv * 40 *dj);	
else if (me->query("weapon/pin") == "�������")
		init_blade(w_lv * 41 *dj);		
else if (me->query("weapon/pin") == "��������")
		init_blade(w_lv * 42 *dj);		
else if (me->query("weapon/pin") == "�߽�����")
		init_blade(w_lv * 43 *dj);	
else if (me->query("weapon/pin") == "�˽�����")
		init_blade(w_lv * 44 *dj);	
else if (me->query("weapon/pin") == "�Ž�����")
		init_blade(w_lv * 45 *dj);	
else if (me->query("weapon/pin") == "ʮ������")
		init_blade(w_lv * 46 *dj);		
else if (me->query("weapon/pin") == "һ�׻���")
		init_blade(w_lv * 47 *dj);			
else if (me->query("weapon/pin") == "���׻���")
		init_blade(w_lv * 48 *dj);			
else if (me->query("weapon/pin") == "���׻���")
		init_blade(w_lv * 49 *dj);			
else if (me->query("weapon/pin") == "�Ľ׻���")
		init_blade(w_lv * 50 *dj);			
else if (me->query("weapon/pin") == "��׻���")
		init_blade(w_lv * 51 *dj);			
else if (me->query("weapon/pin") == "���׻���")
		init_blade(w_lv * 52 *dj);			
else if (me->query("weapon/pin") == "�߽׻���")
		init_blade(w_lv * 53 *dj);			
else if (me->query("weapon/pin") == "�˽׻���")
		init_blade(w_lv * 54 *dj);		
else if (me->query("weapon/pin") == "�Ž׻���")
		init_blade(w_lv * 55 *dj);		
else if (me->query("weapon/pin") == "ʮ�׻���")
		init_blade(w_lv * 56 *dj);			
else if (me->query("weapon/pin") == "���һ��")
		init_blade(w_lv * 57 *dj);				
else if (me->query("weapon/pin") == "������")
		init_blade(w_lv * 58 *dj);					
else if (me->query("weapon/pin") == "�������")
		init_blade(w_lv * 59 *dj);					
else if (me->query("weapon/pin") == "����Ľ�")
		init_blade(w_lv * 60 *dj);					
else if (me->query("weapon/pin") == "������")
		init_blade(w_lv * 61 *dj);					
else if (me->query("weapon/pin") == "�������")
		init_blade(w_lv * 62 *dj);				
else if (me->query("weapon/pin") == "����߽�")
		init_blade(w_lv * 63 *dj);				
else if (me->query("weapon/pin") == "���˽�")
		init_blade(w_lv * 64 *dj);				
else if (me->query("weapon/pin") == "���Ž�")
		init_blade(w_lv * 65 *dj);					
else if (me->query("weapon/pin") == "���ʮ��")
		init_blade(w_lv * 66 *dj);					
else if (me->query("weapon/pin") == "�ɽ�һ��")
		init_blade(w_lv * 67 *dj);					
else if (me->query("weapon/pin") == "�ɽ����")
		init_blade(w_lv * 68 *dj);					
else if (me->query("weapon/pin") == "�ɽ�����")
		init_blade(w_lv * 69 *dj);					
else if (me->query("weapon/pin") == "�ɽ��Ľ�")
		init_blade(w_lv * 70 *dj);					
else if (me->query("weapon/pin") == "�ɽ����")
		init_blade(w_lv * 71 *dj);					
else if (me->query("weapon/pin") == "�ɽ�����")
		init_blade(w_lv * 72 *dj);					
else if (me->query("weapon/pin") == "�ɽ��߽�")
		init_blade(w_lv * 73 *dj);					
else if (me->query("weapon/pin") == "�ɽ�˽�")
		init_blade(w_lv * 74 *dj);					
else if (me->query("weapon/pin") == "�ɽ�Ž�")
		init_blade(w_lv * 75 *dj);					
else if (me->query("weapon/pin") == "�ɽ�ʮ��")
		init_blade(w_lv * 76 *dj);					
else if (me->query("weapon/pin") == "����һ��")
		init_blade(w_lv * 77 *dj);					
else if (me->query("weapon/pin") == "���Ƕ���")
		init_blade(w_lv * 78 *dj);					
else if (me->query("weapon/pin") == "��������")
		init_blade(w_lv * 79 *dj);					
else if (me->query("weapon/pin") == "�����Ľ�")
		init_blade(w_lv * 80 *dj);					
else if (me->query("weapon/pin") == "�������")
		init_blade(w_lv * 81 *dj);					
else if (me->query("weapon/pin") == "��������")
		init_blade(w_lv * 82 *dj);					
else if (me->query("weapon/pin") == "�����߽�")
		init_blade(w_lv * 83 *dj);					
else if (me->query("weapon/pin") == "���ǰ˽�")
		init_blade(w_lv * 84 *dj);					
else if (me->query("weapon/pin") == "���ǾŽ�")
		init_blade(w_lv * 85 *dj);					
else if (me->query("weapon/pin") == "����ʮ��")
		init_blade(w_lv * 86 *dj);					
else if (me->query("weapon/pin") == "����ʮһ��")
		init_blade(w_lv * 87 *dj);					
else if (me->query("weapon/pin") == "����ʮ����")
		init_blade(w_lv * 88 *dj);					
else if (me->query("weapon/pin") == "����ʮ����")
		init_blade(w_lv * 89 *dj);					
else if (me->query("weapon/pin") == "����ʮ�Ľ�")
		init_blade(w_lv * 90 *dj);					
else if (me->query("weapon/pin") == "����ʮ���")
		init_blade(w_lv * 91 *dj);					
else if (me->query("weapon/pin") == "����ʮ����")
		init_blade(w_lv * 92 *dj);					
else if (me->query("weapon/pin") == "����ʮ�߽�")
		init_blade(w_lv * 93 *dj);					
else if (me->query("weapon/pin") == "����ʮ�˽�")
		init_blade(w_lv * 94 *dj);					
else if (me->query("weapon/pin") == "����ʮ�Ž�")
		init_blade(w_lv * 95 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ��")
		init_blade(w_lv * 96 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮһ��")
		init_blade(w_lv * 97 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ����")
		init_blade(w_lv * 98 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ����")
		init_blade(w_lv * 99 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ�Ľ�")
		init_blade(w_lv * 100 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ���")
		init_blade(w_lv * 101 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ����")
		init_blade(w_lv * 102 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ�߽�")
		init_blade(w_lv * 103 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ�˽�")
		init_blade(w_lv * 104 *dj);					
else if (me->query("weapon/pin") == "���Ƕ�ʮ�Ž�")
		init_blade(w_lv * 105 *dj);					
else if (me->query("weapon/pin") == "������ʮ��")
		init_blade(w_lv * 106 *dj);					
else if (me->query("weapon/pin") == "������ʮһ��")
		init_blade(w_lv * 107 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 108 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 109 *dj);					
 if (me->query("weapon/pin") == "������ʮ�Ľ�")
		init_blade(w_lv * 110 *dj);	
else if (me->query("weapon/pin") == "������ʮ���")
		init_blade(w_lv * 111 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 112 *dj);					
else if (me->query("weapon/pin") == "������ʮ�߽�")
		init_blade(w_lv * 113 *dj);					
else if (me->query("weapon/pin") == "������ʮ�˽�")
		init_blade(w_lv * 114 *dj);					
else if (me->query("weapon/pin") == "������ʮ�Ž�")
		init_blade(w_lv * 115 *dj);					
else if (me->query("weapon/pin") == "������ʮ��")
		init_blade(w_lv * 116 *dj);					
else if (me->query("weapon/pin") == "������ʮһ��")
		init_blade(w_lv * 117 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 118 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 119 *dj);					
else if (me->query("weapon/pin") == "������ʮ�Ľ�")
		init_blade(w_lv * 120 *dj);					
else if (me->query("weapon/pin") == "������ʮ���")
		init_blade(w_lv * 121 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 122 *dj);					
else if (me->query("weapon/pin") == "������ʮ�߽�")
		init_blade(w_lv * 123 *dj);					
else if (me->query("weapon/pin") == "������ʮ�˽�")
		init_blade(w_lv * 124 *dj);					
else if (me->query("weapon/pin") == "������ʮ�Ž�")
		init_blade(w_lv * 125 *dj);					
else if (me->query("weapon/pin") == "������ʮ��")
		init_blade(w_lv * 126 *dj);					
else if (me->query("weapon/pin") == "������ʮһ��")
		init_blade(w_lv * 127 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 128 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 129 *dj);					
else if (me->query("weapon/pin") == "������ʮ�Ľ�")
		init_blade(w_lv * 130 *dj);					
else if (me->query("weapon/pin") == "������ʮ���")
		init_blade(w_lv * 131 *dj);					
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 132 *dj);					
else if (me->query("weapon/pin") == "������ʮ�߽�")
		init_blade(w_lv * 133 *dj);					
else if (me->query("weapon/pin") == "������ʮ�˽�")
		init_blade(w_lv * 134 *dj);					
else if (me->query("weapon/pin") == "������ʮ�Ž�")
		init_blade(w_lv * 135 *dj);					
else if (me->query("weapon/pin") == "������ʮ��")
		init_blade(w_lv * 136 *dj);						
else if (me->query("weapon/pin") == "������ʮһ��")
		init_blade(w_lv * 137 *dj);						
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 138 *dj);						
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 139 *dj);						
else if (me->query("weapon/pin") == "������ʮ�Ľ�")
		init_blade(w_lv * 140 *dj);						
else if (me->query("weapon/pin") == "������ʮ���")
		init_blade(w_lv * 141 *dj);						
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 142 *dj);						
else if (me->query("weapon/pin") == "������ʮ�߽�")
		init_blade(w_lv * 143 *dj);						
else if (me->query("weapon/pin") == "������ʮ�˽�")
		init_blade(w_lv * 144 *dj);			
else if (me->query("weapon/pin") == "������ʮ�Ž�")
		init_blade(w_lv * 145 *dj);		
else if (me->query("weapon/pin") == "������ʮ��")
		init_blade(w_lv * 146 *dj);			
else if (me->query("weapon/pin") == "������ʮһ��")
		init_blade(w_lv * 147 *dj);			
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 148 *dj);			
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 149 *dj);			
else if (me->query("weapon/pin") == "������ʮ�Ľ�")
		init_blade(w_lv * 150 *dj);			
else if (me->query("weapon/pin") == "������ʮ���")
		init_blade(w_lv * 151 *dj);			
else if (me->query("weapon/pin") == "������ʮ����")
		init_blade(w_lv * 152 *dj);			
else if (me->query("weapon/pin") == "������ʮ�߽�")
		init_blade(w_lv * 153 *dj);			
else if (me->query("weapon/pin") == "������ʮ�˽�")
		init_blade(w_lv * 154 *dj);			
else if (me->query("weapon/pin") == "������ʮ�Ž�")
		init_blade(w_lv * 155 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ��")
		init_blade(w_lv * 156 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮһ��")
		init_blade(w_lv * 157 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ����")
		init_blade(w_lv * 158 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ����")
		init_blade(w_lv * 159 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ�Ľ�")
		init_blade(w_lv * 160 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ���")
		init_blade(w_lv * 161 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ����")
		init_blade(w_lv * 162 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ�߽�")
		init_blade(w_lv * 163 *dj);			
else if (me->query("weapon/pin") == "���ǰ�ʮ�˽�")
		init_blade(w_lv * 164 *dj);														
else if (me->query("weapon/pin") == "���ǰ�ʮ�Ž�")
		init_blade(w_lv * 165 *dj);				
else if (me->query("weapon/pin") == "���Ǿ�ʮ��")
		init_blade(w_lv * 166 *dj);				
 if (me->query("weapon/pin") == "���һ��")
		init_blade(w_lv * 167 *dj);		
else if (me->query("weapon/pin") == "������")
		init_blade(w_lv * 168 *dj);		
else if (me->query("weapon/pin") == "�������")
		init_blade(w_lv * 169 *dj);		
else if (me->query("weapon/pin") == "����Ľ�")
		init_blade(w_lv * 170 *dj);		
else if (me->query("weapon/pin") == "������")
		init_blade(w_lv * 171 *dj);		
else if (me->query("weapon/pin") == "�������")
		init_blade(w_lv * 172 *dj);		
else if (me->query("weapon/pin") == "����߽�")
		init_blade(w_lv * 173 *dj);		
else if (me->query("weapon/pin") == "���˽�")
		init_blade(w_lv * 174 *dj);		
else if (me->query("weapon/pin") == "���Ž�")
		init_blade(w_lv * 175 *dj);		
else if (me->query("weapon/pin") == "���ʮ��")
		init_blade(w_lv * 176 *dj);		
else if (me->query("weapon/pin") == "���ʮһ��")
		init_blade(w_lv * 177 *dj);		
else if (me->query("weapon/pin") == "���ʮ����")
		init_blade(w_lv * 178 *dj);		
else if (me->query("weapon/pin") == "���ʮ����")
		init_blade(w_lv * 179 *dj);		
else if (me->query("weapon/pin") == "���ʮ�Ľ�")
		init_blade(w_lv * 180 *dj);		
else if (me->query("weapon/pin") == "���ʮ���")
		init_blade(w_lv * 181 *dj);		
else if (me->query("weapon/pin") == "���ʮ����")
		init_blade(w_lv * 182 *dj);		
else if (me->query("weapon/pin") == "���ʮ�߽�")
		init_blade(w_lv * 183 *dj);		
else if (me->query("weapon/pin") == "���ʮ�˽�")
		init_blade(w_lv * 184 *dj);		
else if (me->query("weapon/pin") == "���ʮ�Ž�")
		init_blade(w_lv * 185 *dj);		
else if (me->query("weapon/pin") == "����ʮ��")
		init_blade(w_lv * 186 *dj);		
else if (me->query("weapon/pin") == "����ʮһ��")
		init_blade(w_lv * 187 *dj);		
else if (me->query("weapon/pin") == "����ʮ����")
		init_blade(w_lv * 188 *dj);		
else if (me->query("weapon/pin") == "����ʮ����")
		init_blade(w_lv * 189 *dj);		
else if (me->query("weapon/pin") == "����ʮ�Ľ�")
		init_blade(w_lv * 190 *dj);		
else if (me->query("weapon/pin") == "����ʮ���")
		init_blade(w_lv * 191 *dj);		
else if (me->query("weapon/pin") == "����ʮ����")
		init_blade(w_lv * 192 *dj);		
else if (me->query("weapon/pin") == "����ʮ�߽�")
		init_blade(w_lv * 193 *dj);		
else if (me->query("weapon/pin") == "����ʮ�˽�")
		init_blade(w_lv * 194 *dj);		
else if (me->query("weapon/pin") == "����ʮ�Ž�")
		init_blade(w_lv * 195 *dj);		
else if (me->query("weapon/pin") == "�����ʮ��")
		init_blade(w_lv * 196 *dj);		
	
	setup();
}



int do_duanlian(object weapon,object me)
{
	object obj;
	int w_zhi, w_level;
	string w_or;
	string arg;
		me=this_player();

obj=present("xueye", me);//�ɶɼ���������ϵͳ

	if( !weapon )
		return notify_fail("��Ҫ����ʲô?\n");

	if (me->is_fighting())
		return notify_fail("�������?\n");

	if (me->is_busy())
		return notify_fail("��æ����?\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("��������������޷�����������\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("��������������޷�����������\n");

	if (userp(me) && !me->query_skill_mapped("force"))
		return notify_fail("��û���ڹ�����ʹ���а�!\n");
		
	if(!present("xueye", me))
		return notify_fail("�������û������֮Ѫ�����������㲻��5��\n");
		
	if(!present("xueye", me)&& obj->query_amount()<5)
		return notify_fail("�������û������֮Ѫ������������5��\n");
		
	if ( obj->query_amount()<5)
		return notify_fail("�������û������֮Ѫ������������5��\n");
		
	if( me->query_skill("shenzhao-jing", 1) > 100
            && (int)me->query("max_neili") < 5000 )
		return notify_fail("��������������޷�����������\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����������\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����������\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ���������\n");


	message_vision(HIR "$N����ֱָ������������������ѪҺ����һ˿˿�Ĵ��˽�ȥ��\n" NOR, me);

	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("weapon_max",5);
	me->add("weapon/lv",5);
		obj->add_amount(-5);

		message_vision(HIY "�������һ����һ���������$N�Ľ��壬�����ˣ�\n" NOR,me);
		message_vision(HIG "$N�Ľ��ĵȼ�����ˣ�\n" NOR, me);
	message_vision(HIC "$N�Ľ���������!\n" NOR, me);
		message("vision",ZJCHANNEL+ HIC"��"HIM"��"HIW"��"HIC""+me->query("name")+"("+me->query("id")+")������֮Ѫ��������֮�У������ȼ��õ�������\n" NOR, users());		

	return 1;
}


int do_hui(object weapon)
{
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("��Ҫ�ݻ�ʲô?\n");
	message_vision(HIR "$N���һ����һ���潣��һ���������¡������¡һ������"
			+w_name+HIR"��Ϊ����!\n" NOR,me);
	me->set("weapon/make",0);
	destruct( this_object() );
	me->delete("weapon");

	me->save();

	return 1;
}
/*void owner_is_killed()
{
        write(HIY"ֻ��һ������������"+query("name")+HIY"���ڵ��ϣ��ϳ����ء�\n"NOR);
        this_object()->unequip();
        this_object()->reset_action();
        this_object()->set("name", query("name") + "����Ƭ");
        this_object()->set("value", 0);
        this_object()->set("weapon_prop", 0);
}*/
