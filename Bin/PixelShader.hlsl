struct PS_INPUT
{
	float2 texCoord : TEXCOORD;
};

float4 PSMain(float4 position : SV_POSITION) : SV_Target
{
	return float4(0.2f,0.4f,0.8f,1.0f);
}