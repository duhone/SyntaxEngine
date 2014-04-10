string description = "Basic 2d sprite";

//------------------------------------
float4x4 worldViewProj : WorldViewProjection;
float4 light : Light;

texture colorTexture : Texture0
<
	string ResourceName = "photo.dds";
>;

//------------------------------------
struct vertexInput {
    float3 position				: POSITION;
};

struct vertexOutput {
    float4 hPosition		: POSITION;
    float2 texCoordDiffuse	: TEXCOORD0;
};


//------------------------------------
vertexOutput VS_TransformAndFrame(vertexInput IN) 
{
    vertexOutput OUT;
    OUT.hPosition = mul( float4(IN.position.xyz , 1.0) , worldViewProj);
    OUT.texCoordDiffuse.xy = (IN.position.xy + 0.5);
    OUT.texCoordDiffuse.y = 1.0f - OUT.texCoordDiffuse.y;
    return OUT;
}


//------------------------------------
sampler TextureSampler = sampler_state 
{
    texture = <colorTexture>;
    AddressU  = CLAMP;        
    AddressV  = CLAMP;
    AddressW  = CLAMP;
    MIPFILTER = LINEAR;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
};


//-----------------------------------
float4 PS_Sample( vertexOutput IN): COLOR
{
  float4 diffuseTexture = tex2D( TextureSampler, IN.texCoordDiffuse );
  float3 normal;
  normal.xy = IN.texCoordDiffuse.xy;
  normal.y = 1.0f - normal.y;
  normal.xy = normal.xy*2-1;
  normal.z = sqrt(1-(normal.x*normal.x)-(normal.y*normal.y));
  float bright = saturate(dot(light.xyz,normal))+0.2;
  return bright*diffuseTexture;
}

//-----------------------------------
technique q0_p0_main
{
    pass p0 
    {		
		VertexShader = compile vs_2_0 VS_TransformAndFrame();
		PixelShader  = compile ps_2_0 PS_Sample();
    }
}
