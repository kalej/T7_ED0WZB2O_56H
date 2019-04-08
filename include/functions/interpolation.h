#include <t7types.h>
#include <misc.h>

#ifndef INTERPOLATION_H_
#define INTERPOLATION_H_

#define MAP_I16_I16_I16(X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP) \
	map_i16_i16_i16( ARRAY_LEN(X_AXIS), ARRAY_LEN(Y_AXIS), \
		X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP )
extern i16 map_i16_i16_i16(u32, u32, i16*, i16*, i16, i16, i16*);

#define MAP_I16_I16_U16(X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP) \
	map_i16_i16_u16( ARRAY_LEN(X_AXIS), ARRAY_LEN(Y_AXIS), \
		X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP )
extern u16 map_i16_i16_u16(u32, u32, i16*, i16*, i16, i16, u16*);

#define MAP_i16_i16_u8(X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP) \
	map_i16_i16_u8( ARRAY_LEN(X_AXIS), ARRAY_LEN(Y_AXIS), \
		X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP )
extern u8  map_i16_i16_u8 (u32, u32, i16*, i16*, i16, i16, u8*);

#define MAP_U16_U16_I16(X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP) \
	map_u16_u16_i16( ARRAY_LEN(X_AXIS), ARRAY_LEN(Y_AXIS), \
		X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP )
extern i16 map_u16_u16_i16(u32, u32, u16*, u16*, u16, u16, i16*);

#define MAP_U16_U16_U16(X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP) \
	map_u16_u16_u16( ARRAY_LEN(X_AXIS), ARRAY_LEN(Y_AXIS), \
		X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP )
extern u16 map_u16_u16_u16(u32, u32, u16*, u16*, u16, u16, u16*);

#define MAP_U16_U16_U8(X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP) \
	map_u16_u16_u8( ARRAY_LEN(X_AXIS), ARRAY_LEN(Y_AXIS), \
		X_AXIS, Y_AXIS, X_VAL, Y_VAL, MAP )
extern u8  map_u16_u16_u8 (u32, u32, u16*, u16*, u16, u16, u8*);

#define TAB_I16_I16(AXIS, VALUE, MAP) \
	tab_i16_i16(ARRAY_LEN(AXIS), AXIS, VALUE, MAP)
extern i16 tab_i16_i16(u32, i16*, i16, i16*);

#define TAB_I16_U16(AXIS, VALUE, MAP) \
	tab_i16_u16(ARRAY_LEN(AXIS), AXIS, VALUE, MAP)
extern u16 tab_i16_u16(u32, i16*, i16, u16*);

#define TAB_I16_U8(AXIS, VALUE, MAP) \
	tab_i16_u8(ARRAY_LEN(AXIS), AXIS, VALUE, MAP)
extern u8  tab_i16_u8 (u32, i16*, i16, u8*);

#define TAB_U16_I16(AXIS, VALUE, MAP) \
	tab_u16_i16(ARRAY_LEN(AXIS), AXIS, VALUE, MAP)
extern i16 tab_u16_i16(u32, u16*, u16, i16*);

#define TAB_U16_U16(AXIS, VALUE, MAP) \
	tab_u16_u16(ARRAY_LEN(AXIS), AXIS, VALUE, MAP)
extern u16 tab_u16_u16(u32, u16*, u16, u16*);

#define TAB_U16_U8(AXIS, VALUE, MAP) \
	tab_u16_u8(ARRAY_LEN(AXIS), AXIS, VALUE, MAP)
extern u8  tab_u16_u8 (u32, u16*, u16, u8*);

#endif /* INTERPOLATION_H_ */
