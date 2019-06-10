/*=================================================================
	File created by Yohann NICOLAS.

	Common functions.
 
=================================================================*/

#include "common.h"
#include "error.h"
#include "d2functions.h"

s_shifting shifting;

bool isOnRect(DWORD x, DWORD y, DWORD x0, DWORD y0, DWORD l, DWORD h)
	{return (x>=x0) && (x<x0+l) && (y>y0-h) && (y<=y0);}


void freeMessage(sWinMessage* msg)
{
	msg->managed=1;
	msg->unmanaged=0;
	D2FreeWinMessage(msg);
}


LPWSTR getString(LPWSTR eng)
{
	return eng;
}
#define LANGUAGE(I,ENG) case I : return getString(L##ENG)

LPWSTR getTranslatedString(int stringID)
{
	switch(stringID)
	{
	LANGUAGE( STR_STATS_UNASSIGN_WITH_LIMIT,
		"+Alt: Unassign, +Shift: by %d points");

	LANGUAGE( STR_STATS_UNASSIGN_WITHOUT_LIMIT,
		"+Alt: Unassign, +Shift: all remaining points");

	LANGUAGE( STR_STATS_BASE_MIN,
		"Base: %d (Min: %d)");

	LANGUAGE( STR_SKILLS_UNASSIGN,
		"Un-allocate all skills points");

	LANGUAGE( STR_STASH_PREVIOUS_PAGE,
		"Previous Page (+shift: First Page)");

	LANGUAGE( STR_STASH_NEXT_PAGE,
		"Next Page (+shift: Last not empty Page)");

	LANGUAGE( STR_TOGGLE_TO_PERSONAL,
		"Toggle to Personal Stash");

	LANGUAGE( STR_TOGGLE_TO_SHARED,
		"Toggle to Shared Stash");

	LANGUAGE( STR_STASH_PREVIOUS_INDEX,
		"Previous Index : by %d Pages (+Shift: %d)");

	LANGUAGE( STR_STASH_NEXT_INDEX,
		"Next Index : by %d Pages (+shift: %d)");

	LANGUAGE( STR_PUT_GOLD,
		"Put Gold");

	LANGUAGE( STR_TAKE_GOLD,
		"Take Gold");

	LANGUAGE( STR_PERSONAL_PAGE_NUMBER,
		"Personal Page n %u");

	LANGUAGE( STR_SHARED_PAGE_NUMBER,
		"Shared Page n %u");

	LANGUAGE( STR_NO_SELECTED_PAGE,
		"No selected page");

	LANGUAGE( STR_SHARED_GOLD_QUANTITY,
		"Shared Gold : %u");

	LANGUAGE( STR_PREVIOUS_PAGE,
		"Previous Page");

	LANGUAGE( STR_NEXT_PAGE,
		"Next Page");
	LANGUAGE(STR_SORT,
		"Sort Stash");
	LANGUAGE(STR_COMPOSE,
		"Compose Item");

	default : return L"";
	}
}


/*=================================================================*/

const char* SNONE="";
const char* c_shie[3]={"Shield (Not Class Specific)",SNONE,SNONE};
const char* c_tors[3]={"Body Armor",SNONE,SNONE};
const char* c_gold[3]={"Gold",SNONE,SNONE};
const char* c_bowq[3]={"Arrow",SNONE,SNONE};
const char* c_xboq[3]={"Bolt",SNONE,SNONE};
const char* c_play[3]={"Ear",SNONE,SNONE};
const char* c_herb[3]={"Herb",SNONE,SNONE};
const char* c_poti[3]={"Potion",SNONE,SNONE};
const char* c_ring[3]={"Ring",SNONE,SNONE};
const char* c_elix[3]={"Elixir",SNONE,SNONE};
const char* c_amul[3]={"Amulet",SNONE,SNONE};
const char* c_char[3]={"Charm",SNONE,SNONE};
const char* c_boot[3]={"Boot",SNONE,SNONE};
const char* c_glov[3]={"Glove",SNONE,SNONE};
const char* c_book[3]={"Book",SNONE,SNONE};
const char* c_belt[3]={"Belt",SNONE,SNONE};
const char* c_gem[3]={"Gem",SNONE,SNONE};
const char* c_torc[3]={"Torch",SNONE,SNONE};
const char* c_scro[3]={"Scroll",SNONE,SNONE};
const char* c_scep[3]={"Scepter",SNONE,SNONE};
const char* c_wand[3]={"Wand",SNONE,SNONE};
const char* c_staf[3]={"Staff",SNONE,SNONE};
const char* c_bow[3]={"Bow",SNONE,SNONE};
const char* c_axe[3]={"Axe",SNONE,SNONE};
const char* c_club[3]={"Club",SNONE,SNONE};
const char* c_swor[3]={"Sword",SNONE,SNONE};
const char* c_hamm[3]={"Hammer",SNONE,SNONE};
const char* c_knif[3]={"Knife",SNONE,SNONE};
const char* c_spea[3]={"Spear",SNONE,SNONE};
const char* c_pole[3]={"Polearm",SNONE,SNONE};
const char* c_xbow[3]={"Crossbow",SNONE,SNONE};
const char* c_mace[3]={"Mace",SNONE,SNONE};
const char* c_helm[3]={"Helm",SNONE,SNONE};

const char* c_tpot[3]={"Missile Potion",SNONE,SNONE};
const char* c_ques[3]={"Quest Item",SNONE,SNONE};
const char* c_body[3]={"Body Part",SNONE,SNONE};
const char* c_key[3]={"Key",SNONE,SNONE};
const char* c_tkni[3]={"Throwing Knife",SNONE,SNONE};
const char* c_taxe[3]={"Throwing Axe",SNONE,SNONE};
const char* c_jave[3]={"Javelin",SNONE,SNONE};
const char* c_weap[3]={"Weapon",SNONE,SNONE};
const char* c_mele[3]={"Melee Weapon",SNONE,SNONE};
const char* c_miss[3]={"Missile Weapon",SNONE,SNONE};
const char* c_thro[3]={"Throwing Weapon",SNONE,SNONE};
const char* c_comb[3]={"Combo Weapon",SNONE,SNONE};
const char* c_armo[3]={"Armor",SNONE,SNONE};
const char* c_shld[3]={"Any Shield",SNONE,SNONE};
const char* c_misc[3]={"Miscellaneous",SNONE,SNONE};
const char* c_sock[3]={"Socket Filler",SNONE,SNONE};
const char* c_seco[3]={"Second Hand Item",SNONE,SNONE};
const char* c_rod[3]={"Staves And Rods",SNONE,SNONE};
const char* c_misl[3]={"Missile",SNONE,SNONE};
const char* c_blun[3]={"Blunt",SNONE,SNONE};

const char* c_jewl[3]={"Jewel",SNONE,SNONE};
const char* c_clas[3]={"Class Specific",SNONE,SNONE};
const char* c_amaz[3]={"Amazon Item",SNONE,SNONE};
const char* c_barb[3]={"Barbarian Item",SNONE,SNONE};
const char* c_necr[3]={"Necromancer Item",SNONE,SNONE};
const char* c_pala[3]={"Paladin Item",SNONE,SNONE};
const char* c_sorc[3]={"Sorceress Item",SNONE,SNONE};
const char* c_assn[3]={"Assassin Item",SNONE,SNONE};
const char* c_drui[3]={"Druid Item",SNONE,SNONE};
const char* c_h2h[3]={"Claw",SNONE,SNONE};
const char* c_orb[3]={"Orb",SNONE,SNONE};
const char* c_head[3]={"Voodoo Heads",SNONE,SNONE};
const char* c_ashd[3]={"Paladin Shield",SNONE,SNONE};
const char* c_phlm[3]={"Barbarian Helm",SNONE,SNONE};
const char* c_pelt[3]={"Druid Helm",SNONE,SNONE};
const char* c_cloa[3]={"Cloak",SNONE,SNONE};
const char* c_rune[3]={"Rune",SNONE,SNONE};
const char* c_circ[3]={"Circlet",SNONE,SNONE};
const char* c_hpot[3]={"Healing Potion",SNONE,SNONE};
const char* c_mpot[3]={"Mana Potion",SNONE,SNONE};
const char* c_rpot[3]={"Rejuvenation potion",SNONE,SNONE};
const char* c_spot[3]={"Stamina Potion",SNONE,SNONE};
const char* c_apot[3]={"Antidote Potion",SNONE,SNONE};
const char* c_wpot[3]={"Thawing Potion",SNONE,SNONE};
const char* c_scha[3]={"Small Charm",SNONE,SNONE};
const char* c_mcha[3]={"Large Charm",SNONE,SNONE};
const char* c_lcha[3]={"Grand Charm",SNONE,SNONE};
const char* c_abow[3]={"Amazon Bow",SNONE,SNONE};
const char* c_aspe[3]={"Amazon Spear",SNONE,SNONE};
const char* c_ajav[3]={"Amazon Javelin",SNONE,SNONE};
const char* c_h2h2[3]={"Assassin Claw",SNONE,SNONE};
const char* c_mboq[3]={"Magic Arrow",SNONE,SNONE};
const char* c_mxbq[3]={"Magic Bolt",SNONE,SNONE};
const char* c_gem0[3]={"Chipped Gem",SNONE,SNONE};
const char* c_gem1[3]={"Flawed Gem",SNONE,SNONE};
const char* c_gem2[3]={"Normal Gem",SNONE,SNONE};
const char* c_gem3[3]={"Flawless Gem",SNONE,SNONE};
const char* c_gem4[3]={"Perfect Gem",SNONE,SNONE};
const char* c_gema[3]={"Amethyst",SNONE,SNONE};
const char* c_gemd[3]={"Diamond",SNONE,SNONE};
const char* c_geme[3]={"Emerald",SNONE,SNONE};
const char* c_gemr[3]={"Ruby",SNONE,SNONE};
const char* c_gems[3]={"Sapphire",SNONE,SNONE};
const char* c_gemt[3]={"Topaz",SNONE,SNONE};
const char* c_gemz[3]={"Skull",SNONE,SNONE};

const char* getTypeString (DWORD code)
{
	DWORD lang = 0;//D2GetLang();
	if ((lang == LNG_FRA) || (lang == LNG_DEU)) lang--;
	else lang = 0;
	switch (code)
	{
		case BIN('s','h','i','e') : return c_shie[0];
		case BIN('t','o','r','s') : return c_tors[0];
		case BIN('g','o','l','d') : return c_gold[0];
		case BIN('b','o','w','q') : return c_bowq[0];
		case BIN('x','b','o','q') : return c_xboq[0];
		case BIN('p','l','a','y') : return c_play[0];
		case BIN('h','e','r','b') : return c_herb[0];
		case BIN('p','o','t','i') : return c_poti[0];
		case BIN('r','i','n','g') : return c_ring[0];
		case BIN('e','l','i','x') : return c_elix[0];
		case BIN('a','m','u','l') : return c_amul[0];
		case BIN('c','h','a','r') : return c_char[0];
		case BIN('b','o','o','t') : return c_boot[0];
		case BIN('g','l','o','v') : return c_glov[0];
		case BIN('b','o','o','k') : return c_book[0];
		case BIN('b','e','l','t') : return c_belt[0];
		case BIN('g','e','m',' ') : return c_gem[0];
		case BIN('t','o','r','c') : return c_torc[0];
		case BIN('s','c','r','o') : return c_scro[0];
		case BIN('s','c','e','p') : return c_scep[0];
		case BIN('w','a','n','d') : return c_wand[0];
		case BIN('s','t','a','f') : return c_staf[0];
		case BIN('b','o','w',' ') : return c_bow[0];
		case BIN('a','x','e',' ') : return c_axe[0];
		case BIN('c','l','u','b') : return c_club[0];
		case BIN('s','w','o','r') : return c_swor[0];
		case BIN('h','a','m','m') : return c_hamm[0];
		case BIN('k','n','i','f') : return c_knif[0];
		case BIN('s','p','e','a') : return c_spea[0];
		case BIN('p','o','l','e') : return c_pole[0];
		case BIN('x','b','o','w') : return c_xbow[0];
		case BIN('m','a','c','e') : return c_mace[0];
		case BIN('h','e','l','m') : return c_helm[0];
		case BIN('t','p','o','t') : return c_tpot[0];
		case BIN('q','u','e','s') : return c_ques[0];
		case BIN('b','o','d','y') : return c_body[0];
		case BIN('k','e','y',' ') : return c_key[0];
		case BIN('t','k','n','i') : return c_tkni[0];
		case BIN('t','a','x','e') : return c_taxe[0];
		case BIN('j','a','v','e') : return c_jave[0];
		case BIN('w','e','a','p') : return c_weap[0];
		case BIN('m','e','l','e') : return c_mele[0];
		case BIN('m','i','s','s') : return c_miss[0];
		case BIN('t','h','r','o') : return c_thro[0];
		case BIN('c','o','m','b') : return c_comb[0];
		case BIN('a','r','m','o') : return c_armo[0];
		case BIN('s','h','l','d') : return c_shld[0];
		case BIN('m','i','s','c') : return c_misc[0];
		case BIN('s','o','c','k') : return c_sock[0];
		case BIN('s','e','c','o') : return c_seco[0];
		case BIN('r','o','d',' ') : return c_rod[0];
		case BIN('m','i','s','l') : return c_misl[0];
		case BIN('b','l','u','n') : return c_blun[0];
		case BIN('j','e','w','l') : return c_jewl[0];
		case BIN('c','l','a','s') : return c_clas[0];
		case BIN('a','m','a','z') : return c_amaz[0];
		case BIN('b','a','r','b') : return c_barb[0];
		case BIN('n','e','c','r') : return c_necr[0];
		case BIN('p','a','l','a') : return c_pala[0];
		case BIN('s','o','r','c') : return c_sorc[0];
		case BIN('a','s','s','n') : return c_assn[0];
		case BIN('d','r','u','i') : return c_drui[0];
		case BIN('h','2','h',' ') : return c_h2h[0];
		case BIN('h','2','h','2') : return c_h2h2[0];
		case BIN('o','r','b',' ') : return c_orb[0];
		case BIN('h','e','a','d') : return c_head[0];
		case BIN('a','s','h','d') : return c_ashd[0];
		case BIN('p','h','l','m') : return c_phlm[0];
		case BIN('p','e','l','t') : return c_pelt[0];
		case BIN('c','l','o','a') : return c_cloa[0];
		case BIN('r','u','n','e') : return c_rune[0];
		case BIN('c','i','r','c') : return c_circ[0];
		case BIN('h','p','o','t') : return c_hpot[0];
		case BIN('m','p','o','t') : return c_mpot[0];
		case BIN('r','p','o','t') : return c_rpot[0];
		case BIN('s','p','o','t') : return c_spot[0];
		case BIN('a','p','o','t') : return c_apot[0];
		case BIN('w','p','o','t') : return c_wpot[0];
		case BIN('s','c','h','a') : return c_scha[0];
		case BIN('m','c','h','a') : return c_mcha[0];
		case BIN('l','c','h','a') : return c_lcha[0];
		case BIN('a','b','o','w') : return c_abow[0];
		case BIN('a','s','p','e') : return c_aspe[0];
		case BIN('a','j','a','v') : return c_ajav[0];
		case BIN('m','b','o','q') : return c_mboq[0];
		case BIN('m','x','b','q') : return c_mxbq[0];
		case BIN('g','e','m','0') : return c_gem0[0];
		case BIN('g','e','m','1') : return c_gem1[0];
		case BIN('g','e','m','2') : return c_gem2[0];
		case BIN('g','e','m','3') : return c_gem3[0];
		case BIN('g','e','m','4') : return c_gem4[0];
		case BIN('g','e','m','a') : return c_gema[0];
		case BIN('g','e','m','d') : return c_gemd[0];
		case BIN('g','e','m','e') : return c_geme[0];
		case BIN('g','e','m','r') : return c_gemr[0];
		case BIN('g','e','m','s') : return c_gems[0];
		case BIN('g','e','m','t') : return c_gemt[0];
		case BIN('g','e','m','z') : return c_gemz[0];
		default: return NULL;
	}
}

char* getTypeAString (WORD id, char* lpText, DWORD size)
{
	ItemTypesBIN* itemTypeData = D2GetItemTypesBIN(id);
	if (!itemTypeData)
	{
		strncpy(lpText, "Bad Type", size);
		return lpText;
	}

	const char* string = getTypeString(itemTypeData->code);
	if (!string)
	{
		struct {
			DWORD code;
			BYTE zero;
		} code;
		code.code = itemTypeData->code;
		code.zero = 0;
		strncpy(lpText, (char*)&code, size);
	} else 
		strncpy(lpText, string, size);

	return lpText;
}

LPWSTR getTypeUString (WORD id, LPWSTR lpText, DWORD size)
{
	ItemTypesBIN* itemTypeData = D2GetItemTypesBIN(id);
	if (!itemTypeData)
	{
		mbstowcs(lpText, "Bad Type", size);
		return lpText;
	}
	const char* string = getTypeString(itemTypeData->code);
	if (!string)
	{
		struct {
			DWORD code;
			BYTE zero;
		} code;
		code.code = itemTypeData->code;
		code.zero = 0;
		mbstowcs(lpText, (char*)&code, size);
	} else 
		mbstowcs(lpText, string, size);

	return lpText;
}
/*================================= END OF FILE =================================*/