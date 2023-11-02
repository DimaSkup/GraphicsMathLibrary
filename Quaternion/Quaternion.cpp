////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Quaternion.cpp
// Description:   this file contains an implementation of some functional 
//                for work with quaternions
//
// Created:       30.10.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "Quaternion.h"

namespace MathLib
{


void VECTOR3D_Theta_To_QUAT(QUAT & q, const VECTOR3D & v, const float theta)
{
	// initialization of a quaternion using a 3D direction vector and a rotation angle.
	// The direction vector must be a unit vector, and the angle must be in radians.

	float theta_div_2 = (0.5f) * theta;  // theta / 2

	// calculate the quaternion
	float sinf_theta = sinf(theta_div_2);
	q.x = sinf_theta * v.x;
	q.y = sinf_theta * v.y;
	q.z = sinf_theta * v.z;
	q.w = cosf(theta_div_2);

} // VECTOR3D_Theta_To_QUAT

///////////////////////////////////////////////////////////

void EulerZYX_To_QUAT(QUAT & q,
	const float theta_z,
	const float theta_y,
	const float theta_x)
{
	// this function initializes a rotation quaternion using passed
	// Euler rotation angles which are parallel to z, y, and x axis respectively.

	float cos_z_2 = 0.5f * cosf(theta_z);
	float cos_y_2 = 0.5f * cosf(theta_y);
	float cos_x_2 = 0.5f * cosf(theta_x);
	float sin_z_2 = 0.5f * sinf(theta_z);
	float sin_y_2 = 0.5f * sinf(theta_y);
	float sin_x_2 = 0.5f * sinf(theta_x);

	q.w = (cos_z_2 * cos_y_2 * cos_x_2) + (sin_z_2 * sin_y_2 * sin_x_2);
	q.x = (cos_z_2 * cos_y_2 * sin_x_2) - (sin_z_2 * sin_y_2 * cos_x_2);
	q.y = (cos_z_2 * sin_y_2 * cos_x_2) + (sin_z_2 * cos_y_2 * sin_x_2);
	q.z = (sin_z_2 * cos_y_2 * cos_x_2) - (cos_z_2 * sin_y_2 * sin_x_2);

} // end EulerZYX_To_QUAT

///////////////////////////////////////////////////////////

void QUAT_To_VECTOR3D_Theta(const QUAT & q, VECTOR3D & v, float & theta)
{
	// this function transformates a unit quaternion into a unit 3D direction vector
	// and a rotation angle around it

	// compute a theta (rotation angle)
	theta = acosf(q.w);

	// precomputation for effectiveness improvement
	float inv_sin_theta = 1.0f / sinf(theta);

	// find elements of the vector
	v.x = q.x / inv_sin_theta;
	v.y = q.y / inv_sin_theta;
	v.z = q.z / inv_sin_theta;

	// multiply by 2
	theta *= 2;

} // end QUAT_To_VECTOR3D_Theta

///////////////////////////////////////////////////////////

void QUAT_Add(const QUAT & q1, const QUAT & q2, QUAT & qsum)
{
	// this function adds quaternions q1+q2 and stores the result in qsum

	qsum.w = q1.w + q2.w;
	qsum.x = q1.x + q2.x;
	qsum.y = q1.y + q2.y;
	qsum.z = q1.z + q2.z;

} // end QUAT_Add

///////////////////////////////////////////////////////////

void QUAT_Sub(const QUAT & q1, const QUAT & q2, QUAT & qdiff)
{
	// this function subtracts q2 from q1 and stores the result in qdiff

	qdiff.w = q1.w - q2.w;
	qdiff.x = q1.x - q2.x;
	qdiff.y = q1.y - q2.y;
	qdiff.z = q1.z - q2.z;

} // end QUAT_Sub

///////////////////////////////////////////////////////////

void QUAT_Conjugate(const QUAT & q, QUAT & qconj)
{
	// this function computes a conjugate of a quaternion and
	// stores the result in qconj

	qconj.w = q.w;   // real part
	qconj.x = -q.x;
	qconj.y = -q.y;
	qconj.z = -q.z;

} // end QUAT_Conjugate

///////////////////////////////////////////////////////////

void QUAT_Scale(const QUAT & q, const float scale, QUAT & qs)
{
	// this function scales the q quaternion with the scale value 
	// and stores the result in qs

	qs.w = q.w * scale;
	qs.x = q.x * scale;
	qs.y = q.y * scale;
	qs.z = q.z * scale;

} // end QUAT_Scale

///////////////////////////////////////////////////////////

void QUAT_Scale(QUAT & q, const float scale)
{
	// this function scales the q quaternion with the scale value 
	// and stores the result right into the passed quaternion

	q.w *= scale;
	q.x *= scale;
	q.y *= scale;
	q.z *= scale;

} // end QUAT_Scale

///////////////////////////////////////////////////////////

float QUAT_Norm(const QUAT & q)
{
	// this function returns a norm (length) of the q quaternion

	return sqrtf((q.w*q.w) + (q.x*q.x) + (q.y*q.y) + (q.z*q.z));

} // end QUAT_Norm

///////////////////////////////////////////////////////////

float QUAT_Norm2(const QUAT & q)
{
	// this function returns a square of a norm (length) of the q quaternion;
	// it is very useful when we can compare two norms;

	return (q.w*q.w) + (q.x*q.x) + (q.y*q.y) + (q.z*q.z);

} // end QUAT_Norm2

///////////////////////////////////////////////////////////

void QUAT_Normalize(const QUAT & q, QUAT & qn)
{
	// this function normalizes the q quaternion and
	// stores the result in qn

	// compute 1/length
	float len_inv = 1.0f / sqrtf((q.w*q.w) + (q.x*q.x) + (q.y*q.y) + (q.z*q.z));

	// normalize each component of the q
	qn.w = q.w * len_inv;
	qn.x = q.x * len_inv;
	qn.y = q.y * len_inv;
	qn.z = q.z * len_inv;

} // end QUAT_Normalize

///////////////////////////////////////////////////////////

void QUAT_Normalize(QUAT & q)
{
	// this function normalizes the q quaternion and
	// stores the result right into the input quaternion

	// compute 1/length
	float len_inv = 1.0f / sqrtf((q.w*q.w) + (q.x*q.x) + (q.y*q.y) + (q.z*q.z));

	// normalize each component of the q
	q.w *= len_inv;
	q.x *= len_inv;
	q.y *= len_inv;
	q.z *= len_inv;

} // end QUAT_Normalize

///////////////////////////////////////////////////////////

void QUAT_Unit_Inverse(const QUAT & q, QUAT & qi)
{
	// this function computes the inverse of a unit quaternion and
	// stores the result in qi;
	//
	// note: 1. the input quaternion q must be a unit quaternion
	//       2. the inverse of a unit quaternion is a conjugate quaternion

	qi.w = q.w;
	qi.x = -q.x;
	qi.y = -q.y;
	qi.z = -q.z;

} // end QUAT_Unit_Inverse

///////////////////////////////////////////////////////////

void QUAT_Unit_Inverse(QUAT & q)
{
	// this function computes the inverse of a unit quaternion and
	// stores the result in q;
	//
	// note: 1. the input quaternion q must be a unit quaternion
	//       2. the inverse of a unit quaternion is a conjugate quaternion

	q.x = -q.x;
	q.y = -q.y;
	q.z = -q.z;

} // end QUAT_Unit_Inverse

///////////////////////////////////////////////////////////

void QUAT_Inverse(const QUAT & q, QUAT & qi)
{
	// this function computes the inverse of a quaternion and
	// stores the result in qi;
	//
	// note: for this function there is no need that an input 
	//       quaternion q must be a unit quaternion


	// 1 / q_norm^2
	float norm2_inv = 1.0f / ((q.w*q.w) + (q.x*q.x) + (q.y*q.y )+ (q.z*q.z));

	// q_inverse = q_conjugate / q_norm^2
	qi.w =  q.w * norm2_inv;
	qi.x = -q.x * norm2_inv;
	qi.y = -q.y * norm2_inv;
	qi.z = -q.z * norm2_inv;

} // end QUAT_Inverse

///////////////////////////////////////////////////////////

void QUAT_Mul(const QUAT & q1, const QUAT & q2, QUAT & qprod)
{
	// this function multiplies q1*q2;
	// note: in general, quaternion multiplication is no commutative so
	// q1*q2 != q2*q1
	//
	// qprod.w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
	// qprod.x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
	// qprod.y = q1.w*q2.y - q1.x*q2.z + q1.y*q2.w - q1.z*q2.x;
	// qprod.z = q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w;

	// to reduce the count of multiplications there is using
	// common factors allocation
	float prd_0 = (q1.z - q1.y) * (q2.y - q2.z);
	float prd_1 = (q1.w + q1.x) * (q2.w + q2.x);
	float prd_2 = (q1.w - q1.x) * (q2.y + q2.z);
	float prd_3 = (q1.y + q1.z) * (q2.w - q2.x);
	float prd_4 = (q1.z - q1.x) * (q2.x - q2.y);
	float prd_5 = (q1.z + q1.x) * (q2.x + q2.y);
	float prd_6 = (q1.w + q1.y) * (q2.w - q2.z);
	float prd_7 = (q1.w - q1.y) * (q2.w + q2.z);
	float prd_8 = prd_5 + prd_6 + prd_7;
	float prd_9 = 0.5f * (prd_4 + prd_8);

	// compute the final result using temporal variables
	qprod.w = prd_0 + prd_9 - prd_5;
	qprod.x = prd_1 + prd_9 - prd_8;
	qprod.y = prd_2 + prd_9 - prd_7;
	qprod.z = prd_3 + prd_9 - prd_6;

} // end QUAT_Mul

} // end namespace MathLib
