
cbuffer cbProj : register(b0)
{
	matrix m_Projection;
};

cbuffer cbView : register(b1)
{
	matrix m_View;
};

cbuffer cbWorld : register(b2)
{
	matrix m_World;
};

struct VS_INPUT
{
	float3 m_Position : POSITION;
	float2 m_TexCoord : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 m_Position : SV_POSITION;
	float2 m_TexCoord : TEXCOORD;
};

VS_OUTPUT VSMain(VS_INPUT vsInput)
{
	VS_OUTPUT output;

	output.m_Position = float4(vsInput.m_Position, 1);
	output.m_Position = mul(output.m_Position, m_World);
	output.m_Position = mul(output.m_Position, m_View);
	output.m_Position = mul(output.m_Position, m_Projection);
	output.m_TexCoord = vsInput.m_TexCoord;
	return output;
}